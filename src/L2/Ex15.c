#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  printf("Antes da inversão de linhas:\n");
  print_matrix(size, size, matrix);

  invert_rows(size, size, matrix);
  printf("Depois da inversão de linhas:\n");
  print_matrix(size, size, matrix);

  return EXIT_SUCCESS;
}
