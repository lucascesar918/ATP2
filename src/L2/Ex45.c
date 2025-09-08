#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];
  double transposed[size][size];
  double product[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);
  print_matrix(size, size, matrix);
  printf("Transpondo matriz...\n");

  transpose_matrix(size, size, matrix, transposed);
  print_matrix(size, size, transposed);

  printf("Multiplicando pela transposta...\n");
  multiply_matrices(size, size, matrix, size, size, transposed, product);
  print_matrix(size, size, product);

  return EXIT_SUCCESS;
}
