#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix_a[size][size];
  double matrix_b[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix_a);
  rand_matrix_populate(size, size, matrix_b);
  print_matrix(size, size, matrix_a);
  print_matrix(size, size, matrix_b);

  printf("As matrizes %s equivalentes.\n",
         matrixcmp(size, size, matrix_a, matrix_b) ? "são" : "não são");

  return EXIT_SUCCESS;
}
