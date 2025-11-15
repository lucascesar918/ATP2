#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void introduction() {
  printf("Sistema de Gerenciamento de Arquivos\n");
  printf("_____________________________________________\n");
}

static void trim_newline(char *s) {
  s[strcspn(s, "\r\n")] = '\0';
}

static int read_line(char *buf, size_t sz) {
  if (!fgets(buf, sz, stdin))
    return 0;
  trim_newline(buf);
  return 1;
}

static int copy_file(const char *src, const char *dst, unsigned char *buf,
                     size_t buf_sz) {
  FILE *fa = fopen(src, "rb");
  if (!fa) {
    fprintf(stderr, "Erro ao abrir '%s'\n", src);
    return 1;
  }
  FILE *fb = fopen(dst, "wb");
  if (!fb) {
    fprintf(stderr, "Erro ao criar destino '%s'\n", dst);
    fclose(fa);
    return 1;
  }
  size_t n;
  while ((n = fread(buf, 1, buf_sz, fa)) > 0) {
    if (fwrite(buf, 1, n, fb) != n) {
      fprintf(stderr, "Erro ao escrever em '%s'\n", dst);
      fclose(fa);
      fclose(fb);
      return 1;
    }
  }
  fclose(fa);
  fclose(fb);
  return 0;
}

static int move_file(const char *src, const char *dst, unsigned char *buf,
                     size_t buf_sz) {
  if (rename(src, dst) == 0) {
    printf("Movido com sucesso (rename).\n");
    return 0;
  }
  if (copy_file(src, dst, buf, buf_sz) != 0)
    return 1;
  if (remove(src) == 0) {
    printf("Movido com sucesso (copiado e removido o arquivo de origem).\n");
    return 0;
  }
  fprintf(stderr, "Erro ao remover '%s' depois de copiar\n", src);
  return 1;
}

static int print_file(const char *path, unsigned char *buf, size_t buf_sz) {
  FILE *fa = fopen(path, "rb");
  if (!fa) {
    fprintf(stderr, "Erro ao abrir '%s'\n", path);
    return 1;
  }
  if (fseek(fa, 0, SEEK_END) == 0) {
    long size = ftell(fa);
    if (size >= 0) {
      printf("--- Tamanho: %ld bytes ---\n", size);
    }
    fseek(fa, 0, SEEK_SET);
  }
  size_t n;
  while ((n = fread(buf, 1, buf_sz, fa)) > 0) {
    if (fwrite(buf, 1, n, stdout) != n) {
      fprintf(stderr, "Erro ao imprimir '%s'\n", path);
      fclose(fa);
      return 1;
    }
  }
  printf("\n--- Fim do arquivo ---\n");
  fclose(fa);
  return 0;
}

static int append_line(const char *path, const char *line) {
  FILE *fa = fopen(path, "ab");
  if (!fa) {
    fprintf(stderr, "Erro ao abrir '%s'\n", path);
    return 1;
  }
  size_t len = strlen(line);
  if (len > 0) {
    if (fwrite(line, 1, len, fa) != len || fwrite("\n", 1, 1, fa) != 1) {
      fprintf(stderr, "Erro ao escrever em '%s'\n", path);
      fclose(fa);
      return 1;
    }
  }
  fclose(fa);
  printf("Texto acrescentado.\n");
  return 0;
}

static int delete_file(const char *path) {
  if (remove(path) == 0) {
    printf("Arquivo removido.\n");
    return 0;
  }
  fprintf(stderr, "Falha ao remover '%s'\n", path);
  return 1;
}

int main(int argc, char *argv[]) {
  char input[512];
  char path_a[256];
  char path_b[256];
  const size_t BUF_SZ = 4096;
  unsigned char *buf = malloc(BUF_SZ);
  if (!buf) {
    fprintf(stderr, "Memória insuficiente\n");
    return 1;
  }
  introduction();
  while (1) {
    printf("\nComandos: copy, move, print, echo, delete, quit\n");
    printf(">> ");
    if (!read_line(input, sizeof(input)))
      break;
    if (strcmp(input, "quit") == 0) {
      break;
    } else if (strcmp(input, "copy") == 0) {
      printf("Origem: ");
      if (!read_line(path_a, sizeof(path_a)))
        continue;
      printf("Destino: ");
      if (!read_line(path_b, sizeof(path_b)))
        continue;
      if (copy_file(path_a, path_b, buf, BUF_SZ) == 0)
        printf("Cópia concluída.\n");
    } else if (strcmp(input, "move") == 0) {
      printf("Origem: ");
      if (!read_line(path_a, sizeof(path_a)))
        continue;
      printf("Destino: ");
      if (!read_line(path_b, sizeof(path_b)))
        continue;
      move_file(path_a, path_b, buf, BUF_SZ);
    } else if (strcmp(input, "print") == 0) {
      printf("Arquivo a imprimir: ");
      if (!read_line(path_a, sizeof(path_a)))
        continue;
      print_file(path_a, buf, BUF_SZ);
    } else if (strcmp(input, "echo") == 0) {
      printf("Arquivo (append): ");
      if (!read_line(path_a, sizeof(path_a)))
        continue;
      printf("Texto para acrescentar (uma linha): ");
      if (!read_line(input, sizeof(input)))
        continue;
      append_line(path_a, input);
    } else if (strcmp(input, "delete") == 0) {
      printf("Arquivo a deletar: ");
      if (!read_line(path_a, sizeof(path_a)))
        continue;
      printf("Tem certeza que deseja deletar '%s'? (y/N): ", path_a);
      if (!read_line(input, sizeof(input)))
        continue;
      if (input[0] == 'y' || input[0] == 'Y')
        delete_file(path_a);
      else
        printf("Operação cancelada.\n");
    } else {
      printf("Comando desconhecido.\n");
    }
  }
  free(buf);
  printf("Saindo.\n");
  return 0;
}