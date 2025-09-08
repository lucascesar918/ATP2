#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef struct {
  int col;
  int row;
} Position;

void print_matrix(const int cols, const int rows,
                  const double matrix[cols][rows]);

void print_int_matrix(const int cols, const int rows,
                      const int matrix[cols][rows]);

void print_row(const int size, const double row[size]);

void fill_matrix(const int cols, const int rows, double matrix[cols][rows],
                 double num);

void fill_int_matrix(const int cols, const int rows, int matrix[cols][rows],
                     int num);

double sum_matrix_elements(const int cols, const int rows,
                           const double matrix[cols][rows]);

bool matrixcmp(const int cols, const int rows, const double matrix1[cols][rows],
               const double matrix2[cols][rows]);

double rand_between(int min, int max);

int rand_int_between(int min, int max);

void rand_matrix_populate(const int cols, const int rows,
                          double matrix[cols][rows]);

void rand_int_matrix_populate(const int cols, const int rows,
                              int matrix[cols][rows]);

void transpose_matrix(int cols, int rows, double src_mat[cols][rows],
                      double dest_mat[rows][cols]);

double sum_diagonal(int size, double matrix[size][size]);

bool is_symmetric(int size, double matrix[size][size]);

void rotate_matrix_clockwise(const int cols, const int rows,
                             double src_matrix[cols][rows],
                             double dest_matrix[rows][cols]);

void rotate_matrix_anticlockwise(const int cols, const int rows,
                                 double src_matrix[cols][rows],
                                 double dest_matrix[rows][cols]);

void matrix_times_scalar(const int cols, const int rows, double scalar,
                         double src_matrix[cols][rows],
                         double dest_matrix[cols][rows]);

int matrix_times_matrix(const int cols1, const int rows1,
                        double matrix1[cols1][rows1], const int cols2,
                        const int rows2, double matrix2[cols2][rows2],
                        double matrix3[rows1][cols2]);

double largest_in(const int cols, const int rows, double matrix[cols][rows]);

double nth_largest_in(const int cols, const int rows, double matrix[cols][rows],
                      int n);

double smallest_in(const int cols, const int rows, double matrix[cols][rows]);

int count_even(const int cols, const int rows, int matrix[cols][rows]);

double average_of(const int cols, const int rows, double matrix[cols][rows]);

bool is_diagonal(const int size, const double matrix[size][size]);

void matrixcp(const int cols, const int rows,
              const double src_matrix[cols][rows],
              double dest_matrix[cols][rows]);

void invert_rows(const int cols, const int rows, double matrix[cols][rows]);

void invert_cols(const int cols, const int rows, double matrix[cols][rows]);

int nth_prime(int n);

void fill_with_primes(const int cols, const int rows,
                      double matrix[cols][rows]);

Position find_value(const int cols, const int rows,
                    const int matrix[cols][rows], int search_value);

bool is_identity(const int size, int matrix[size][size]);

void multiply_matrices(const int cols_a, const int rows_a,
                       double matrix_a[cols_a][rows_a], const int cols_b,
                       const int rows_b, double matrix_b[cols_b][rows_b],
                       double matrix_c[cols_a][rows_b]);

void sum_columns(const int cols, const int rows, double matrix[cols][rows],
                 double column_sums[cols]);

bool is_permutation_matrix(const int size, double matrix[size][size]);

void sort_rows(const int cols, const int rows, double matrix[cols][rows]);

void sort_cols(const int cols, const int rows, double matrix[cols][rows]);

void cofactor_of(const int size, double matrix[size][size],
                 double temp[size][size], int p, int q);

double determinant_of(const int size, double matrix[size][size]);

bool are_orthogonal(const int size, double matrix_a[size][size],
                    double matrix_b[size][size]);

int count_num(const int cols, const int rows, int matrix[cols][rows], int num);

Position binary_search_matrix(const int cols, const int rows,
                              int matrix[cols][rows], int target);

bool is_vandermonde(const int size, int matrix[size][size]);

bool is_reflexive(const int size, double matrix[size][size]);

bool is_orthogonal(const int size, double matrix[size][size]);

bool is_cauchy(const int size, double matrix[size][size]);

bool is_hankel(const int cols, const int rows, double matrix[cols][rows]);

bool is_toeplitz(const int cols, const int rows, double matrix[cols][rows]);

bool is_householder(const int size, double matrix[size][size]);

double sum_below_diagonal(const int size, double matrix[size][size]);

double average_above_diagonal(const int size, double matrix[size][size]);

bool is_circular_hankel(const int size, double matrix[size][size]);

bool is_circulant(const int size, double matrix[size][size]);

double product_of_sec_diagonal(const int size, double matrix[size][size]);

double is_sylvester(const int size, double matrix[size][size]);

#endif
