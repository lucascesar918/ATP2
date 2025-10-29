#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo>\n");
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  fseek(fd, 0, SEEK_END);
  long end_offset = ftell(fd);

  if (0 == end_offset) {
    printf("O arquivo está vazio!\n");
    fclose(fd);
    return 0;
  }

  printf("O tamanho do arquivo %s é %ld bytes!\n", argv[1], end_offset);

  fclose(fd);
  return 0;
}
