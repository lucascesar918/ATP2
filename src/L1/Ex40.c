/*
 * Escreva um programa em C que declare um array de 8
 * inteiros e passe esse array para uma função que
 * inverta a ordem dos elementos do array.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int *array, const size_t size);
void print_array(const int *array, const size_t size);
void swap(int *index1, int *index2);
void invert_array(int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 6;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("");
    return EXIT_FAILURE;
  }

  srand(time(NULL));
  populate_array(array, arrlen);

  printf("Antes de inverter:\n");
  print_array(array, arrlen);
  invert_array(array, arrlen);
  printf("\n\n");
  printf("Depois de inverter:\n");
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(-100, 100);
}

void print_array(const int *array, const size_t size) {
  printf("{ ");
  for (size_t l = 0; l < size; l++) {
    printf("%3d%s", array[l], l == size - 1 ? " }" : ", ");
  }
}

void swap(int *index1, int *index2) {
  int aux = *index1;

  *index1 = *index2;
  *index2 = aux;
}

void invert_array(int *array, const size_t size) {
  size_t j = 0, k = size - 1;

  while (j < k) {
    swap(&array[j++], &array[k--]);
  }
}
