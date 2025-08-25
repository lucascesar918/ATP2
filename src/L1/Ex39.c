/*
 * Escreva um programa em C que declare um array de 6
 * inteiros e passe esse array para uma função que conte
 * quantos elementos são positivos.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int *array, const size_t size);
int count_positive(const int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("");
    return EXIT_FAILURE;
  }

  srand(time(NULL));
  populate_array(array, arrlen);

  printf("O array tem %d números positivos.\n", count_positive(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(-100, 100);
}

int count_positive(const int *array, const size_t size) {
  int count = 0;
  for (size_t k = 0; k < size; k++)
    if (array[k] > 0)
      count++;

  return count;
}
