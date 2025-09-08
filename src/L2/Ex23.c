#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  double matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  double identity_matrix[3][3] = {
      {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
  double zero_row_matrix[3][3] = {
      {1.0, 2.0, 3.0}, {0.0, 0.0, 0.0}, {4.0, 5.0, 6.0}};

  print_matrix(size, size, matrix);
  printf("A determinante equivale a %.3f.\n", determinant_of(size, matrix));

  print_matrix(size, size, identity_matrix);
  printf("A determinante equivale a %.3f.\n",
         determinant_of(size, identity_matrix));

  print_matrix(size, size, zero_row_matrix);
  printf("A determinante equivale a %.3f.\n",
         determinant_of(size, zero_row_matrix));

  return EXIT_SUCCESS;
}
