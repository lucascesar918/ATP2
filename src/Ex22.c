/*
 * Escreva um programa em C que conte o número de elementos
 * pares e ímpares em um array de 20 inteiros.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, const size_t size);
int rand_between(int min, int max);
void print_array(int *array, const size_t size);
int count_odd(int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 20;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);

  printf("O array contém %d ímpares e %d pares\n", count_odd(array, arrlen),
         arrlen - count_odd(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(-100, 100);
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

int count_odd(int *array, const size_t size) {
  int count = 0;

  for (size_t c = 0; c < size; c++)
    if (array[c] % 2 != 0)
      count++;

  return count;
}
