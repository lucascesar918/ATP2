#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 3;
  const int rows = 2;

  double original_mat[cols][rows];
  double transposed_mat[rows][cols];

  srand(time(null));
  rand_matrix_populate(cols, rows, original_mat);

  print_matrix(cols, rows, original_mat);
  transpose_matrix(cols, rows, original_mat, transposed_mat);

  printf("Imprimindo matriz transposta...\n");
  print_matrix(rows, cols, transposed_mat);

  return EXIT_SUCCESS;
}
