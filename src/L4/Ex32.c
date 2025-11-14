#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 4096
#define BUF_SIZE 8192

typedef struct {
  char *path;
  off_t size;
} FileEntry;

static void add_entry(FileEntry **arr, size_t *count, size_t *cap,
                      const char *path, off_t size) {
  if (*count >= *cap) {
    *cap = (*cap == 0) ? 64 : (*cap * 2);
    *arr = realloc(*arr, (*cap) * sizeof(FileEntry));
    if (!*arr) {
      perror("realloc");
      exit(1);
    }
  }
  (*arr)[*count].path = strdup(path);
  (*arr)[*count].size = size;
  (*count)++;
}

static void traverse(const char *dirpath, FileEntry **arr, size_t *count,
                     size_t *cap) {
  DIR *d = opendir(dirpath);
  if (!d) {
    fprintf(stderr, "não pode abrir '%s': %s\n", dirpath, strerror(errno));
    return;
  }
  struct dirent *e;
  char full[MAX_PATH];
  struct stat st;

  while ((e = readdir(d))) {
    if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
      continue;
    if (snprintf(full, sizeof(full), "%s/%s", dirpath, e->d_name) >=
        (int)sizeof(full))
      continue;
    if (lstat(full, &st) != 0)
      continue;
    if (S_ISDIR(st.st_mode)) {
      traverse(full, arr, count, cap);
    } else if (S_ISREG(st.st_mode)) {
      add_entry(arr, count, cap, full, st.st_size);
    }
  }
  closedir(d);
}

static int cmp_size(const void *a, const void *b) {
  const FileEntry *fa = a;
  const FileEntry *fb = b;
  if (fa->size < fb->size)
    return -1;
  if (fa->size > fb->size)
    return 1;
  return strcmp(fa->path, fb->path);
}

static int same_file(const char *a, const char *b) {
  FILE *fa = fopen(a, "rb");
  FILE *fb = fopen(b, "rb");
  if (!fa || !fb) {
    if (fa)
      fclose(fa);
    if (fb)
      fclose(fb);
    return 0;
  }
  unsigned char ba[BUF_SIZE], bb[BUF_SIZE];
  size_t ra, rb;
  int equal = 1;
  while (1) {
    ra = fread(ba, 1, BUF_SIZE, fa);
    rb = fread(bb, 1, BUF_SIZE, fb);
    if (ra != rb || memcmp(ba, bb, ra) != 0) {
      equal = 0;
      break;
    }
    if (ra == 0)
      break;
  }
  fclose(fa);
  fclose(fb);
  return equal;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <diretório>\n", argv[0]);
    return 1;
  }
  FileEntry *files = NULL;
  size_t count = 0, cap = 0;
  traverse(argv[1], &files, &count, &cap);
  if (count == 0) {
    printf("Nenhum arquivo encontrado.\n");
    return 0;
  }
  qsort(files, count, sizeof(FileEntry), cmp_size);

  int *marked = calloc(count, sizeof(int));
  if (!marked) {
    perror("calloc");
    return 1;
  }

  size_t groups = 0;
  for (size_t i = 0; i < count; ++i) {
    if (marked[i])
      continue;

    size_t j = i + 1;
    int found = 0;
    for (; j < count && files[j].size == files[i].size; ++j) {
      if (!marked[j] && same_file(files[i].path, files[j].path)) {
        if (!found) {
          groups++;
          printf("\nGrupo %zu:\n", groups);
          printf("%s\n", files[i].path);
          found = 1;
        }
        printf("%s\n", files[j].path);
        marked[j] = 1;
      }
    }
  }

  if (groups == 0)
    printf("Nenhuma duplicata encontrada.\n");

  for (size_t i = 0; i < count; ++i)
    free(files[i].path);
  free(files);
  free(marked);
  return 0;
}
