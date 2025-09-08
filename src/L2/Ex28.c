#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int matrix[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  print_int_matrix(4, 4, matrix);

  printf("Procurar por qual valor?\n>> ");
  int search_value;
  scanf("%d", &search_value);
  Position res = binary_search_matrix(4, 4, matrix, search_value);

  if (res.row == -1) {
    printf("Número não encontrado.\n");
    return EXIT_SUCCESS;
  }

  printf("Número encontrado na linha %d e coluna %d.\n", res.row + 1,
         res.col + 1);

  return EXIT_SUCCESS;
}
