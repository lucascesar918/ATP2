#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols_a = 2;
  const int rows_a = 3;

  const int cols_b = 3;
  const int rows_b = 3;

  double matrix_a[cols_a][rows_a];
  double matrix_b[cols_b][rows_b];
  double matrix_c[cols_a][rows_b];
  double matrix_d[2][2];

  srand(time(NULL));
  rand_matrix_populate(cols_a, rows_a, matrix_a);
  rand_matrix_populate(cols_b, rows_b, matrix_b);

  print_matrix(cols_a, rows_a, matrix_a);
  print_matrix(cols_b, rows_b, matrix_b);

  printf("Multiplicando as matrizes...\n");
  multiply_matrices(cols_a, rows_a, matrix_a, cols_b, rows_b, matrix_b,
                    matrix_c);
  print_matrix(cols_a, rows_b, matrix_c);

  printf("Armazenando numa matriz 2x2...\n");
  matrixcp(2, 2, matrix_c, matrix_d);
  print_matrix(2, 2, matrix_d);

  return EXIT_SUCCESS;
}
