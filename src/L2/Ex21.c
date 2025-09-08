#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];
  double outlier[3][3] = {{1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}};

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  print_matrix(size, size, matrix);
  printf("Essa matriz %s de permutação.\n",
         is_permutation_matrix(size, matrix) ? "é" : "não é");

  print_matrix(size, size, outlier);
  printf("Essa matriz %s de permutação.\n",
         is_permutation_matrix(size, outlier) ? "é" : "não é");

  return EXIT_SUCCESS;
}
