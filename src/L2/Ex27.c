#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;
  double matrix[size][size];
  double aux_matrix[size][size];

  srand(time(NULL));

  rand_matrix_populate(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("Multiplicar a matriz por qual escalar?\n>> ");
  int scalar;
  scanf("%d", &scalar);

  matrix_times_scalar(size, size, scalar, matrix, aux_matrix);
  print_matrix(size, size, aux_matrix);

  return EXIT_SUCCESS;
}
