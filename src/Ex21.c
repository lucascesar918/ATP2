/*
  Escreva um programa em C que encontre o maior e o menor
  elemento em um array de 10 inteiros.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, size_t size);
void print_array(int *array, size_t size);
int rand_between(int min, int max);
void find_min_and_max(const int *array, size_t size, int *min, int *max);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int *array = malloc(sizeof(int) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  int maior, menor;
  find_min_and_max(array, arrlen, &maior, &menor);
  printf("O maior valor do array é %d e o menor é %d.\n", maior, menor);

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_between(-100, 100);
}

void print_array(int *array, size_t size) {
  for (int i = 0; i < size; i++)
    printf("[%2dº]: %2d\n", i + 1, *(array + i));
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

void find_min_and_max(const int *array, size_t size, int *min, int *max) {
  *min = array[0];
  *max = array[0];

  if (size == 1)
    return;

  for (size_t j = 1; j < size; j++) {
    if (array[j] > *max)
      *max = array[j];
    if (array[j] < *min)
      *min = array[j];
  }
}
