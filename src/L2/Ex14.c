#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];
  double dest[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  printf("Antes da cópia: \n");
  print_matrix(size, size, matrix);
  print_matrix(size, size, dest);

  matrixcp(size, size, matrix, dest);
  printf("Depois da cópia: \n");
  print_matrix(size, size, matrix);
  print_matrix(size, size, dest);

  return EXIT_SUCCESS;
}
