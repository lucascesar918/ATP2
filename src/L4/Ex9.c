#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int id;
} GenericStruct;

size_t get_file_size(FILE *fd) {
  long current_pos = ftell(fd);
  fseek(fd, 0, SEEK_END);
  size_t fsize = (size_t)ftell(fd);
  fseek(fd, current_pos, SEEK_SET);

  return fsize;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos insuficientes!\n\nUso: %s <arquivo fonte>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    perror("Falha ao abrir o arquivo");
    return 1;
  }

  printf("A struct genérica possui um tamanho de %ld bytes (incluindo padding "
         "externo).\n",
         sizeof(GenericStruct));
  printf("O arquivo contém %lu registros da struct genérica!\n",
         get_file_size(fd) / sizeof(GenericStruct));

  fclose(fd);
  return 0;
}