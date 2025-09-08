#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 5;

  double matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  print_matrix(size, size, matrix);
  printf("A matriz %s simétrica\n", is_symmetric(size, matrix) ? "é" : "não é");

  fill_matrix(size, size, matrix, 1.0);
  print_matrix(size, size, matrix);
  printf("A matriz %s simétrica\n", is_symmetric(size, matrix) ? "é" : "não é");

  return EXIT_SUCCESS;
}
