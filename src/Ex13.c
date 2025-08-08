/*
  Escreva um programa em C que declare um array de 5 inteiros.
  Use um ponteiro para acessar e imprimir todos os elementos do array.
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
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

void populate_array(int *array, size_t size) {
  for (int j = 0; j < size; j++)
    array[j] = rand_between(-100, 100);
}

void print_array(int *array, size_t size) {
  for (int i = 0; i < size; i++)
    printf("[%2d°]: %2d\n", i + 1, *(array + i));
}
