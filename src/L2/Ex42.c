#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("%s uma Matriz de Householder.\n",
         is_householder(size, matrix) ? "É" : "Não é");

  return EXIT_SUCCESS;
}
