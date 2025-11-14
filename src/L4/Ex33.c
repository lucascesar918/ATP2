// Compilar usando a flag -z noexecstack no GCC para desabilitar a
// pilha executável (só vai evitar mostrar um warning chato, mas funciona
// normalmente sem).
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

static int init_file(const char *path, size_t n) {
  GenericStruct *arr = malloc(n * sizeof(GenericStruct));
  if (!arr) {
    perror("malloc");
    return 1;
  }

  for (size_t i = 0; i < n; ++i) {
    snprintf(arr[i].name, MAX_NAME_LENGTH, "Aluno%04zu", i + 1);
    arr[i].age = 18 + (int)(i % 10);
    arr[i].height = 1.50 + (double)(i % 50) / 100.0;
  }

  int cmp_name(const void *a, const void *b) {
    return strcmp(((const GenericStruct *)a)->name,
                  ((const GenericStruct *)b)->name);
  }
  qsort(arr, n, sizeof(GenericStruct), cmp_name);

  FILE *f = fopen(path, "wb");
  if (!f) {
    perror("fopen");
    free(arr);
    return 1;
  }

  if (fwrite(arr, sizeof(GenericStruct), n, f) != n) {
    perror("fwrite");
    fclose(f);
    free(arr);
    return 1;
  }

  fclose(f);
  free(arr);
  printf("Arquivo '%s' criado com %zu registros (ordenados).\n", path, n);
  return 0;
}

static long file_binary_search(const char *path, const char *target) {
  FILE *f = fopen(path, "rb");
  if (!f) {
    perror("fopen");
    return -1;
  }

  struct stat st;
  if (fstat(fileno(f), &st) != 0) {
    perror("fstat");
    fclose(f);
    return -1;
  }

  size_t rec_size = sizeof(GenericStruct);
  if (st.st_size % rec_size != 0) {
    fprintf(stderr, "Arquivo com tamanho inválido\n");
    fclose(f);
    return -1;
  }
  size_t n = st.st_size / rec_size;
  long lo = 0, hi = (long)n - 1;

  GenericStruct buf;
  while (lo <= hi) {
    long mid = lo + (hi - lo) / 2;
    if (fseek(f, mid * rec_size, SEEK_SET) != 0) {
      perror("fseek");
      fclose(f);
      return -1;
    }
    if (fread(&buf, rec_size, 1, f) != 1) {
      perror("fread");
      fclose(f);
      return -1;
    }
    int cmp = strcmp(target, buf.name);
    int cmp_name(const void *a, const void *b) {
      return strcmp(((const GenericStruct *)a)->name,
                    ((const GenericStruct *)b)->name);
    }

    if (cmp == 0) {
      fclose(f);
      return mid;
    } else if (cmp < 0) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  fclose(f);
  return -1;
}

static int read_record_at(const char *path, size_t idx, GenericStruct *out) {
  FILE *f = fopen(path, "rb");
  if (!f) {
    perror("fopen");
    return 1;
  }
  if (fseek(f, idx * sizeof(GenericStruct), SEEK_SET) != 0) {
    perror("fseek");
    fclose(f);
    return 1;
  }
  if (fread(out, sizeof(GenericStruct), 1, f) != 1) {
    perror("fread");
    fclose(f);
    return 1;
  }
  fclose(f);
  return 0;
}

static void usage(const char *prog) {
  fprintf(
      stderr,
      "Uso:\n"
      "  %s init <arquivo> <n_registros>    # cria arquivo ordenado\n"
      "  %s search <arquivo> <nome>         # busca por nome (busca binária)\n",
      prog, prog);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    usage(argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "init") == 0) {
    if (argc != 4) {
      usage(argv[0]);
      return 1;
    }
    const char *path = argv[2];
    size_t n = (size_t)atoi(argv[3]);
    if (n == 0) {
      fprintf(stderr, "n_registros deve ser > 0\n");
      return 1;
    }
    return init_file(path, n);
  } else if (strcmp(argv[1], "search") == 0) {
    if (argc != 4) {
      usage(argv[0]);
      return 1;
    }
    const char *path = argv[2];
    const char *name = argv[3];
    long idx = file_binary_search(path, name);
    if (idx < 0) {
      printf("Registro '%s' não encontrado.\n", name);
      return 0;
    }
    GenericStruct g;
    if (read_record_at(path, (size_t)idx, &g) != 0)
      return 1;
    printf("Registro encontrado no índice %ld:\n", idx);
    printf("  Nome: %s\n  Idade: %d\n  Altura: %.2f\n", g.name, g.age,
           g.height);
    return 0;
  }

  usage(argv[0]);
  return 1;
}
