/*
  Escreva um programa em C que declare um array de 5 inteiros e use
  aritmética de ponteiros para somar 10 a cada elemento do array. Imprima
  o array resultante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, size_t size);
void print_array(int *array, size_t size);
int rand_between(int min, int max);

int main(int argc, char *argv[]) {
  const size_t arrlen = 5;
  int *array = malloc(sizeof(int) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  printf("Antes da soma por 10 em cada elemento:\n");
  print_array(array, arrlen);

  printf("Depois da soma por 10 em cada elemento:\n");
  sum_ten(array, arrlen);
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_between(-100, 100);
}

void print_array(int *array, size_t size) {
  for (int i = 0; i < size; i++)
    printf("[%2d°]: %2d\n", i + 1, *(array + i));
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

void sum_ten(int *array, size_t size) {
  for (int c = 0; c < size; c++)
    *(array + c) += 10;
}
