#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 3;
  const int rows = 4;

  double matrix[cols][rows];
  double transposed[cols][rows];

  srand(time(NULL));
  rand_matrix_populate(cols, rows, matrix);
  print_matrix(cols, rows, matrix);

  printf("Calculando a transposta...\n");
  transpose_matrix(cols, rows, matrix, transposed);
  print_matrix(cols, rows, transposed);

  return EXIT_SUCCESS;
}
