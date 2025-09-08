#include "utils.h"
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOLERANCE 0.000001

void print_matrix(const int cols, const int rows,
                  const double matrix[cols][rows]) {
  printf("Imprimindo matriz...\n");
  for (int j = 0; j < cols; j++) {
    for (int k = 0; k < rows; k++)
      printf("[%2d,%2d]: %4.4f%c", k + 1, j + 1, matrix[j][k],
             k == rows - 1 ? '\n' : '\t');
  }
}

void print_int_matrix(const int cols, const int rows,
                      const int matrix[cols][rows]) {
  printf("Imprimindo matriz...\n");
  for (int j = 0; j < cols; j++) {
    for (int k = 0; k < rows; k++)
      printf("[%2d,%2d]: %2d%c", k + 1, j + 1, matrix[j][k],
             k == rows - 1 ? '\n' : '\t');
  }
}

double sum_matrix_elements(const int cols, const int rows,
                           const double matrix[cols][rows]) {
  double sum = 0;

  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      sum += matrix[j][k];

  return sum;
}

bool matrixcmp(const int cols, const int rows, const double matrix1[cols][rows],
               const double matrix2[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix1[j][k] != matrix2[j][k])
        return false;
  return true;
}

double rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

int rand_int_between(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void rand_matrix_populate(const int cols, const int rows,
                          double matrix[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      matrix[j][k] = (double)rand_between(-10000, 10000) / 100;
}

void rand_int_matrix_populate(const int cols, const int rows,
                              int matrix[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      matrix[j][k] = rand_between(-100, 100);
}

void transpose_matrix(int cols, int rows, double src_mat[cols][rows],
                      double dest_mat[rows][cols]) {
  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      dest_mat[j][i] = src_mat[i][j];
}
double sum_diagonal(int size, double matrix[size][size]) {
  double sum = 0;

  for (int i = 0; i < size; i++)
    sum += matrix[i][i];

  return sum;
}

bool is_symmetric(int size, double matrix[size][size]) {
  for (int i = 0; i < size; i++)
    for (int j = i; j < size; j++)
      if (matrix[i][j] != matrix[j][i])
        return false;
  return true;
}

void fill_matrix(const int cols, const int rows, double matrix[cols][rows],
                 double num) {
  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      matrix[i][j] = num;
}

void fill_int_matrix(const int cols, const int rows, int matrix[cols][rows],
                     int num) {
  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      matrix[i][j] = num;
}

void rotate_matrix_clockwise(const int cols, const int rows,
                             double src_matrix[cols][rows],
                             double dest_matrix[rows][cols]) {
  transpose_matrix(cols, rows, src_matrix, dest_matrix);

  double aux;

  for (int i = 0; i < cols; i++)
    for (int j = 0, span = rows - 1; j < span; j++, span--) {
      aux = dest_matrix[i][j];
      dest_matrix[i][j] = dest_matrix[i][span];
      dest_matrix[i][span] = aux;
    }
}

void rotate_matrix_anticlockwise(const int cols, const int rows,
                                 double src_matrix[cols][rows],
                                 double dest_matrix[rows][cols]) {
  transpose_matrix(cols, rows, src_matrix, dest_matrix);

  double aux;

  for (int i = 0; i < rows; i++)
    for (int j = 0, span = cols - 1; j < span; j++, span--) {
      aux = dest_matrix[j][i];
      dest_matrix[j][i] = dest_matrix[span][i];
      dest_matrix[span][i] = aux;
    }
}

void matrix_times_scalar(const int cols, const int rows, double scalar,
                         double src_matrix[cols][rows],
                         double dest_matrix[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      dest_matrix[j][k] = src_matrix[j][k] * scalar;
}

int matrix_times_matrix(const int cols1, const int rows1,
                        double matrix1[cols1][rows1], const int cols2,
                        const int rows2, double matrix2[cols2][rows2],
                        double matrix3[rows1][cols2]) {
  if (cols1 != rows2)
    return 1;

  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < cols2; j++) {
      matrix3[i][j] = 0.0;
      for (int k = 0; k < cols1; k++)
        matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
    }

  return 0;
}

double largest_in(const int cols, const int rows, double matrix[cols][rows]) {
  double largest = matrix[0][0];

  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix[j][k] > largest)
        largest = matrix[j][k];

  return largest;
}

double nth_largest_in(const int cols, const int rows, double matrix[cols][rows],
                      int n) {
  int total = cols * rows;
  double temp_array[total];

  int index = 0;
  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      temp_array[index++] = matrix[i][j];

  for (int i = 0; i < total - 1; i++)
    for (int j = 0; j < total - i - 1; j++)
      if (temp_array[j] < temp_array[j + 1]) {
        double temp = temp_array[j];
        temp_array[j] = temp_array[j + 1];
        temp_array[j + 1] = temp;
      }

  return temp_array[n - 1];
}

double smallest_in(const int cols, const int rows, double matrix[cols][rows]) {
  double smallest = matrix[0][0];

  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix[j][k] < smallest)
        smallest = matrix[j][k];

  return smallest;
}

double nth_smallest_in(const int cols, const int rows,
                       double matrix[cols][rows], int n) {
  int total = cols * rows;
  double temp_array[total];

  int index = 0;
  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      temp_array[index++] = matrix[i][j];

  for (int i = 0; i < total - 1; i++)
    for (int j = 0; j < total - i - 1; j++)
      if (temp_array[j] < temp_array[j + 1]) {
        double temp = temp_array[j];
        temp_array[j] = temp_array[j + 1];
        temp_array[j + 1] = temp;
      }

  return temp_array[total - n - 1];
}

int count_even(const int cols, const int rows, int matrix[cols][rows]) {
  int count = 0;

  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix[j][k] % 2 == 0)
        count++;

  return count;
}

double average_of(const int cols, const int rows, double matrix[cols][rows]) {
  return sum_matrix_elements(cols, rows, matrix) / (cols * rows);
}

bool is_diagonal(const int size, const double matrix[size][size]) {
  for (int j = 0; j < size; j++)
    for (int k = 0; k < size; k++) {
      if (j == k)
        continue;

      if (matrix[j][k] != 0)
        return false;
    }

  return true;
}

void matrixcp(const int cols, const int rows,
              const double src_matrix[cols][rows],
              double dest_matrix[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      dest_matrix[j][k] = src_matrix[j][k];
}

void invert_rows(const int cols, const int rows, double matrix[cols][rows]) {
  double aux;
  for (int j = 0; j < cols; j++)
    for (int a = 0, b = cols - 1; a < b; a++, b--) {
      aux = matrix[j][a];
      matrix[j][a] = matrix[j][b];
      matrix[j][b] = aux;
    }
}

void invert_cols(const int cols, const int rows, double matrix[cols][rows]) {
  double aux;
  for (int j = 0; j < rows; j++)
    for (int a = 0, b = rows - 1; a < b; a++, b--) {
      aux = matrix[a][j];
      matrix[a][j] = matrix[b][j];
      matrix[b][j] = aux;
    }
}

int nth_prime(int n) {
  if (n == 0)
    return 2;
  if (n == 1)
    return 3;

  return 6 * (n - 1) + 1;
}

void fill_with_primes(const int cols, const int rows,
                      double matrix[cols][rows]) {
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      matrix[j][k] = (double)nth_prime(rand_int_between(0, 10));
}

Position find_value(const int cols, const int rows,
                    const int matrix[cols][rows], int search_value) {
  Position pos = {-1, -1};

  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix[j][k] == search_value) {
        pos.col = j;
        pos.row = k;
        return pos;
      }

  return pos;
}

bool is_identity(const int size, int matrix[size][size]) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      if (i == j) {
        if (matrix[i][j] != 1)
          return false;
      } else {
        if (matrix[i][j] != 0) {
          return false;
        }
      }
    }

  return true;
}

bool is_identity_double(const int size, double matrix[size][size]) {
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) {
      if (i == j) {
        if (matrix[i][j] != 1.0)
          return false;
      } else {
        if (matrix[i][j] != 0.0) {
          return false;
        }
      }
    }

  return true;
}

void multiply_matrices(const int cols_a, const int rows_a,
                       double matrix_a[cols_a][rows_a], const int cols_b,
                       const int rows_b, double matrix_b[cols_b][rows_b],
                       double matrix_c[cols_a][rows_b]) {
  if (rows_a != cols_b)
    return;

  for (int i = 0; i < cols_a; i++) {
    for (int j = 0; j < rows_b; j++) {
      matrix_c[i][j] = 0.0;
      for (int k = 0; k < rows_a; k++) {
        matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }
}

void sum_columns(const int cols, const int rows, double matrix[cols][rows],
                 double column_sums[cols]) {
  for (int j = 0; j < cols; j++) {
    column_sums[j] = 0.0;
    for (int i = 0; i < rows; i++) {
      column_sums[j] += matrix[i][j];
    }
  }
}

void print_row(const int size, const double row[size]) {
  printf("Imprimindo linha...\n");
  for (int j = 0; j < size; j++)
    printf("%.3f\n", row[j]);
}

bool is_permutation_matrix(const int size, double matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    int ones_in_row = 0;
    for (int j = 0; j < size; j++)
      if (matrix[i][j] == 1.0)
        ones_in_row++;
      else if (matrix[i][j] != 0.0)
        return false;
    if (ones_in_row != 1)
      return false;
  }

  for (int j = 0; j < size; j++) {
    int ones_in_col = 0;
    for (int i = 0; i < size; i++)
      if (matrix[i][j] == 1.0)
        ones_in_col++;
    if (ones_in_col != 1)
      return false;
  }

  return true;
}

void sort_rows(const int cols, const int rows, double matrix[cols][rows]) {
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows - 1; j++) {
      for (int k = 0; k < rows - j - 1; k++) {
        if (matrix[i][k] > matrix[i][k + 1]) {
          double temp = matrix[i][k];
          matrix[i][k] = matrix[i][k + 1];
          matrix[i][k + 1] = temp;
        }
      }
    }
  }
}

void sort_cols(const int cols, const int rows, double matrix[cols][rows]) {
  for (int j = 0; j < rows; j++)
    for (int i = 0; i < cols - 1; i++)
      for (int k = 0; k < cols - i - 1; k++)
        if (matrix[k][j] > matrix[k + 1][j]) {
          double temp = matrix[k][j];
          matrix[k][j] = matrix[k + 1][j];
          matrix[k + 1][j] = temp;
        }
}

void cofactor_of(const int size, double matrix[size][size],
                 double temp[size][size], int p, int q) {
  int i = 0, j = 0;
  for (int row = 0; row < size; row++)
    for (int col = 0; col < size; col++)
      if (row != p && col != q) {
        temp[i][j++] = matrix[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
}

double determinant_of(const int size, double matrix[size][size]) {
  double determinant = 0.0;

  if (size == 1)
    return matrix[0][0];

  double temp[size][size];

  for (int j = 0; j < size; j++) {
    cofactor_of(size, matrix, temp, 0, j);
    determinant += pow(-1, j) * matrix[0][j] * determinant_of(size - 1, temp);
  }
  return determinant;
}

bool are_orthogonal(const int size, double matrix_a[size][size],
                    double matrix_b[size][size]) {
  double transpose_a[size][size];
  double product[size][size];

  transpose_matrix(size, size, matrix_a, transpose_a);
  multiply_matrices(size, size, transpose_a, size, size, matrix_b, product);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (fabs(product[i][j] - 0.0) > DBL_EPSILON) {
        return false;
      }
    }
  }

  return true;
}

int count_num(const int cols, const int rows, int matrix[cols][rows], int num) {
  int count = 0;
  for (int j = 0; j < cols; j++)
    for (int k = 0; k < rows; k++)
      if (matrix[j][k] == num)
        count++;

  return count;
}

Position binary_search_matrix(const int cols, const int rows,
                              int matrix[cols][rows], int target) {
  Position pos = {-1, -1};
  int left = 0;
  int right = rows * cols - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int mid_row = mid / rows;
    int mid_col = mid % rows;

    int current_value = matrix[mid_row][mid_col];

    if (current_value == target) {
      pos.row = mid_row;
      pos.col = mid_col;
      return pos;
    } else if (current_value < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return pos;
}

bool is_vandermonde(const int size, int matrix[size][size]) {
  for (int i = 0; i < size; i++)
    for (int j = 1; j < size; j++)
      if (matrix[i][j] != pow(matrix[i][1], j))
        return false;

  return true;
}

bool is_reflexive(const int size, double matrix[size][size]) {
  return determinant_of(size, matrix) == -1 && is_orthogonal(size, matrix);
}

bool is_orthogonal(const int size, double matrix[size][size]) {
  double transposed[size][size];
  double product[size][size];

  transpose_matrix(size, size, matrix, transposed);
  multiply_matrices(size, size, matrix, size, size, transposed, product);

  return is_identity_double(size, product);
}

bool is_cauchy(const int size, double matrix[size][size]) {
  if (size <= 0)
    return false;

  if (size == 1)
    return true;

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (matrix[i][j] == 0.0)
        return false;

  for (int i = 1; i < size; i++)
    for (int j = 1; j < size; j++) {
      double expected_diff =
          1.0 / matrix[i][0] + 1.0 / matrix[0][j] - 1.0 / matrix[0][0];
      double actual_diff = 1.0 / matrix[i][j];

      if ((actual_diff - expected_diff) > TOLERANCE ||
          (expected_diff - actual_diff) > TOLERANCE)
        return false;
    }

  return true;
}

bool is_hankel(const int cols, const int rows, double matrix[cols][rows]) {
  if (cols == 1 && rows == 1)
    return true;

  for (int i = 0; i < cols - 1; i++)
    for (int j = 0; j < rows - 1; j++)
      if ((matrix[i][j + 1] - matrix[i + 1][j]) > TOLERANCE ||
          (matrix[i + 1][j] - matrix[i][j + 1]) > TOLERANCE)
        return false;

  return true;
}

bool is_toeplitz(const int cols, const int rows, double matrix[cols][rows]) {
  for (int i = 0; i < cols - 1; i++)
    for (int j = 0; j < rows - 1; j++)
      if (fabs(matrix[i][j] - matrix[i + 1][j + 1]) > TOLERANCE)
        return false;

  return true;
}

bool is_householder(const int size, double matrix[size][size]) {
  return is_symmetric(size, matrix) && is_orthogonal(size, matrix);
}

double sum_below_diagonal(const int size, double matrix[size][size]) {
  double sum = 0.0;

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (i > j)
        sum += matrix[i][j];

  return sum;
}

double average_above_diagonal(const int size, double matrix[size][size]) {
  if (size <= 1)
    return 0.0;

  double sum = 0.0;
  int count = 0;

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (i < j) {
        sum += matrix[i][j];
        count++;
      }

  if (count == 0)
    return 0.0;

  return sum / count;
}

bool is_circular_hankel(const int size, double matrix[size][size]) {
  if (!is_hankel(size, size, matrix))
    return false;

  for (int i = 1; i < size; i++)
    if (fabs(matrix[i][0] - matrix[i - 1][size - 1]) > DBL_EPSILON)
      return false;

  return true;
}

bool is_circulant(const int size, double matrix[size][size]) {
  if (size <= 1)
    return true;

  for (int i = 1; i < size; i++)
    for (int j = 0; j < size; j++) {
      int prev_j = (j - 1 + size) % size;
      if (fabs(matrix[i][j] - matrix[i - 1][prev_j]) > DBL_EPSILON)
        return false;
    }

  return true;
}

double product_of_sec_diagonal(const int size, double matrix[size][size]) {
  double product = 1.0;

  for (int i = 0; i < size; i++) {
    int j = size - 1 - i;
    product *= matrix[i][j];
  }

  return product;
}

double is_sylvester(const int size, double matrix[size][size]) {
  return is_symmetric(size, matrix) && is_orthogonal(size, matrix);
}
