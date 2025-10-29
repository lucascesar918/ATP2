#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "r");

  if (!fd) {
    perror("Erro ao abrir arquivo para leitura.");
    return 1;
  }

  int sum = 0;
  char ch;

  while ((ch = fgetc(fd)) != EOF) {
    if (ch >= '0' && ch <= '9')
      sum += (int)ch - 48;
  }

  printf("A soma dos números do arquivo resultam em %d.\n", sum);

  fclose(fd);
  return 0;
}
