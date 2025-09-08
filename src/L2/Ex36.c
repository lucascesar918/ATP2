#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 5;

  double matrix[size][size];

  srand(time(NULL));
  fill_with_primes(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("Ordenando as colunas...\n");
  sort_cols(size, size, matrix);
  print_matrix(size, size, matrix);

  return EXIT_SUCCESS;
}
