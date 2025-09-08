#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  int matrix[size][size];
  int outlier[size][size];

  srand(time(NULL));
  rand_int_matrix_populate(size, size, matrix);

  fill_int_matrix(size, size, outlier, 0);
  outlier[0][0] = 1;
  outlier[1][1] = 1;
  outlier[2][2] = 1;

  print_int_matrix(size, size, matrix);
  printf("Essa matriz %s uma matriz identidade.\n",
         is_identity(size, matrix) ? "é" : "não é");

  print_int_matrix(size, size, outlier);
  printf("Essa matriz %s uma matriz identidade.\n",
         is_identity(size, outlier) ? "é" : "não é");

  return EXIT_SUCCESS;
}
