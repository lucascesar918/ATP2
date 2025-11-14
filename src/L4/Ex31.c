#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH 4096

size_t get_dir_size(const char *path) {
  DIR *dir = opendir(path);
  if (!dir) {
    fprintf(stderr, "Erro ao abrir o diretório '%s'\n", path);
    return 0;
  }

  struct dirent *entry;
  struct stat file_stat;
  size_t total_size = 0;
  char full_path[MAX_PATH];

  while ((entry = readdir(dir))) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

    if (stat(full_path, &file_stat) == 0)
      if (S_ISREG(file_stat.st_mode))
        total_size += file_stat.st_size;
  }

  closedir(dir);
  return total_size;
}

void print_size_formatted(size_t size) {
  const char *units[] = {"B", "KB", "MB", "GB"};
  int unit = 0;
  double formatted_size = size;

  while (formatted_size >= 1024 && unit < 3) {
    formatted_size /= 1024;
    unit++;
  }

  printf("Tamanho total: %.2f %s\n", formatted_size, units[unit]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <diretório>\n", argv[0]);
    return 1;
  }

  size_t total_size = get_dir_size(argv[1]);
  if (total_size == 0) {
    fprintf(stderr,
            "Erro ao calcular o tamanho do diretório ou diretório vazio\n");
    return 1;
  }

  printf("Diretório: %s\n", argv[1]);
  print_size_formatted(total_size);

  return 0;
}
