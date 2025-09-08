#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 4;

  double matrix[size][size];

  srand(time(NULL));
  fill_with_primes(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("%s uma Matriz de Cauchy.\n", is_cauchy(size, matrix) ? "É" : "Não é");

  return EXIT_SUCCESS;
}
