#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 3;
  const int rows = 3;

  srand(time(NULL));

  double mat[cols][rows];
  rand_matrix_populate(cols, rows, mat);
  print_matrix(cols, rows, mat);

  return EXIT_SUCCESS;
}
