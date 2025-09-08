#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  int matrix[size][size];

  srand(time(NULL));
  rand_int_matrix_populate(size, size, matrix);

  print_int_matrix(size, size, matrix);
  printf("Na matriz há %d números pares!\n", count_even(size, size, matrix));

  return EXIT_SUCCESS;
}
