#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 4;
  const int rows = 3;

  double matrix[cols][rows];
  double column_sums[cols];

  srand(time(NULL));
  rand_matrix_populate(cols, rows, matrix);

  print_matrix(cols, rows, matrix);

  printf("Somando colunas...\n");
  sum_columns(cols, rows, matrix, column_sums);

  print_row(cols, column_sums);

  return EXIT_SUCCESS;
}
