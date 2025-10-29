#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "r");

  int count = 0;
  double sum = 0;
  double current_number;
  int scan_result;

  while (!feof(fd)) {
    scan_result = fscanf(fd, "%lf", &current_number);

    if (scan_result == 1) {
      count++;
      sum += current_number;
    } else if (scan_result == 0) {
      if (fgetc(fd) == EOF)
        break;
    } else if (scan_result == EOF)
      break;
  }

  if (count == 0)
    printf("Nenhum número encontrado.\n");
  else
    printf("A média dos números encontrados é %.2lf.\n", sum / count);

  fclose(fd);
  return 0;
}
