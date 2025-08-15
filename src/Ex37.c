/*
 * Escreva um programa em C que declare um array de 5 inteiros
 * e passe esse array para uma função que calcule a média dos
 * elementos do array.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int *array, const size_t size);
int array_summation(int *array, const size_t size);
float array_avg(int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 5;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("");
    return EXIT_FAILURE;
  }

  srand(time(NULL));
  populate_array(array, arrlen);

  printf("A média aritmética dos valores do array é %.2f.\n",
         array_avg(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(1, 100);
}

int array_summation(int *array, const size_t size) {
  int sum = 0;

  for (size_t k = 0; k < size; k++)
    sum += array[k];

  return sum;
}

float array_avg(int *array, const size_t size) {
  return (float)array_summation(array, size) / (float)size;
}
