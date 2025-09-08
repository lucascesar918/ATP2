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

  printf("A matriz %s Hankel Circular.\n",
         is_circular_hankel(size, matrix) ? "é" : "não é");

  return EXIT_SUCCESS;
}
