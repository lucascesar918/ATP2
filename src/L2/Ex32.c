#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 2;
  double matrix[size][size];
  double outlier[2][2] = {{-1, 0}, {0, 1}};

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);
  print_matrix(size, size, matrix);

  printf("%s uma Matriz de Reflexão!\n",
         is_reflexive(size, matrix) ? "É" : "Não é");

  print_matrix(size, size, outlier);
  printf("%s uma Matriz de Reflexão!\n",
         is_reflexive(size, outlier) ? "É" : "Não é");

  return EXIT_SUCCESS;
}
