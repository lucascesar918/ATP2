#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

void print_matrix(const int size1, const int size2,
                  const double matrix[size1][size2]);

double sum_matrix_elements(const int size1, const int size2,
                           const double matrix[size1][size2]);

bool matrixcmp(const int size1, const int size2,
               const double matrix1[size1][size2],
               const double matrix2[size1][size2]);

double rand_between(int min, int max);

void rand_matrix_populate(const int size1, const int size2,
                          double matrix[size1][size2]);

unsigned long long compute_path(int n);

unsigned long long recursive_path(int n, int j, int k);

#endif
