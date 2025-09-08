#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  int matrix[size][size];
  int outlier[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  srand(time(NULL));
  rand_int_matrix_populate(size, size, matrix);

  print_int_matrix(size, size, matrix);
  printf("%s uma matriz esparsa.\n",
         count_num(size, size, matrix, 0) > size * size ? "É" : "Não é");

  int zeroes = count_num(size, size, outlier, 0);
  print_int_matrix(size, size, outlier);
  printf("%s uma matriz esparsa.\n",
         zeroes > size * size - zeroes ? "É" : "Não é");

  return EXIT_SUCCESS;
}
