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

  printf("A média dos elementos da matriz equivale a %.3f.\n", average_of(size, size, matrix));

  return EXIT_SUCCESS;
}
