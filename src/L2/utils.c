#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(const int size1, const int size2,
                  const double matrix[size1][size2]) {
  printf("Imprimindo matriz...\n");
  for (int j = 0; j < size1; j++) {
    for (int k = 0; k < size2; k++)
      printf("[%1d,%1d]: %3.3f%c", k + 1, j + 1, matrix[j][k],
             k == size2 - 1 ? '\n' : '\t');
  }
}

double sum_matrix_elements(const int size1, const int size2,
                           const double matrix[size1][size2]) {
  double sum = 0;

  for (int j = 0; j < size1; j++)
    for (int k = 0; k < size2; k++)
      sum += matrix[j][k];

  return sum;
}

bool matrixcmp(const int size1, const int size2,
               const double matrix1[size1][size2],
               const double matrix2[size1][size2]) {
  for (int j = 0; j < size1; j++)
    for (int k = 0; k < size2; k++)
      if (matrix1[j][k] != matrix2[j][k])
        return false;
  return true;
}

double rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

void rand_matrix_populate(const int size1, const int size2,
                          double matrix[size1][size2]) {
  for (int j = 0; j < size1; j++)
    for (int k = 0; k < size2; k++)
      matrix[j][k] = (double)rand_between(-10000, 10000) / 100;
}

unsigned long long compute_path(int n) { return recursive_path(n, 1, 1); }

unsigned long long recursive_path(int n, int j, int k) {
  // Não compensa a segurança de checar por 0 em toda a call stack,
  // então fica a critério da implementação interface.
  if (n == j || n == k) {
    return 1;
  }

  return recursive_path(n, j + 1, k) + recursive_path(n, j, k + 1);
}
