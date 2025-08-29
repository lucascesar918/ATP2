#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 4;
  const int rows = 4;
  double matrix[cols][rows];

  srand(time(NULL));

  rand_matrix_populate(cols, rows, matrix);
  print_matrix(cols, rows, matrix);
  printf("A soma dos elementos da matriz equivale a %.3f.\n",
         sum_matrix_elements(cols, rows, matrix));

  return EXIT_SUCCESS;
}
