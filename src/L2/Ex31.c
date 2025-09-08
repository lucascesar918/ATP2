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

  printf("%s uma Matriz de Vandermonde!\n", is_vandermonde(size, matrix) ? "É" : "Não é");

  return EXIT_SUCCESS;
}
