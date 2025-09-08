#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 4;

  double matrix[size][size];
  double outlier[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  fill_matrix(size, size, outlier, 0.0);
  outlier[0][0] = 1;
  outlier[1][1] = 2;
  outlier[3][3] = 3;

  print_matrix(size, size, matrix);
  printf("A matriz %s diagonal.\n", is_diagonal(size, matrix) ? "é" : "não é");
  print_matrix(size, size, outlier);
  printf("A matriz %s diagonal.\n", is_diagonal(size, outlier) ? "é" : "não é");

  return EXIT_SUCCESS;
}
