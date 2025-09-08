#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 4;

  double matrix[size][size];
  double rotated_matrix[size][size];

  srand(time(NULL));
  rand_matrix_populate(size, size, matrix);

  print_matrix(size, size, matrix);
  printf("Rotacionando a matriz no sentido horário...\n");
  rotate_matrix_clockwise(size, size, matrix, rotated_matrix);
  print_matrix(size, size, rotated_matrix);

  return EXIT_SUCCESS;
}
