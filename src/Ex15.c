/*
  Escreva um programa em C que declare um array de 7 inteiros e
  use um ponteiro para calcular a soma dos elementos do array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, size_t size);
void print_array(int *array, size_t size);
int array_summation(int *array, size_t size);
int rand_between(int min, int max);

int main(int argc, char *argv[]) {
  const size_t arrlen = 7;
  int *array = malloc(sizeof(int) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  printf("A soma dos números do array resulta em %d.\n",
         array_summation(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_between(-100, 100);
}

int array_summation(int *array, size_t size) {
  int sum = 0;
  for (int c = 0; c < size; c++)
    sum += *(array + c);

  return sum;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
