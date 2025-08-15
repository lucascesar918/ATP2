/*
 * Escreva um programa em C que declare um array de 10
 * inteiros e passe esse array para uma função que encontre
 * o maior elemento do array.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int *array, const size_t size);
int find_greatest(const int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("");
    return EXIT_FAILURE;
  }

  srand(time(NULL));
  populate_array(array, arrlen);

  printf("O maior número do array é %d\n", find_greatest(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(1, 1000);
}

int find_greatest(const int *array, const size_t size) {
  if (size == 1)
    return array[0];

  int greatest = array[0];

  for (size_t k = 1; k < size; k++)
    if (array[k] > greatest)
      greatest = array[k];

  return greatest;
}
