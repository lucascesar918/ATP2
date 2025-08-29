#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int cols = 2;
  const int rows = 2;

  double matrix1[cols][rows];
  double matrix2[cols][rows];

  rand_matrix_populate(cols, rows, matrix1);
  printf("Matriz A:\n");
  print_matrix(cols, rows, matrix1);
  rand_matrix_populate(cols, rows, matrix2);
  printf("Matriz B:\n");
  print_matrix(cols, rows, matrix2);

  printf("Matriz A e Matriz A%s são iguais!\n",
         matrixcmp(cols, rows, matrix1, matrix1) ? "" : " não");

  printf("Matriz A e Matriz B%s são iguais!\n",
         matrixcmp(cols, rows, matrix1, matrix2) ? "" : " não");

  return EXIT_SUCCESS;
}
