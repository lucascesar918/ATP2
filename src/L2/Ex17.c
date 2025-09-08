#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const int size = 3;

  int matrix[size][size];

  srand(time(NULL));
  rand_int_matrix_populate(size, size, matrix);
  print_int_matrix(size, size, matrix);

  printf("Procurar qual valor na matriz?\n>> ");
  int search_pattern;
  scanf("%d", &search_pattern);

  Position search_res = find_value(size, size, matrix, search_pattern);

  if (search_res.col == -1) {
    printf("Valor não encontrado na matriz.\n");
    return EXIT_SUCCESS;
  }

  printf("Valor encontrado na linha %d e coluna %d.\n", search_res.row + 1,
         search_res.col + 1);

  return EXIT_SUCCESS;
}
