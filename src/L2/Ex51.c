#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];

  srand(time(NULL));
  fill_with_primes(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("O produto da diagonal secundária equivale a %.3f.\n",
         product_of_sec_diagonal(size, matrix));

  return EXIT_SUCCESS;
}
