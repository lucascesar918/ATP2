#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 4;

  double matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("O terceiro maior valor da matriz é %.3f.\n", nth_largest_in(size, size, matrix, 3));

  return EXIT_SUCCESS;
}
