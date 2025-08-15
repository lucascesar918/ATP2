/*
 * Escreva um programa em C que use um array de ponteiros para
 * armazenar 5 números inteiros e encontre o maior valor entre eles.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_numbers(int *array, size_t size);
int rand_between(int min, int max);
void fill_ptr_array(int *src_array[], int dest_array[], size_t size);
void init_ptr_array(int *ptr_array[], size_t size);
void free_ptr_array(int *ptr_array[], size_t size);
int greatest_of_ptr_array(int *ptr_array[], size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 5;
  int *numbers = malloc(sizeof(int) * arrlen);
  int **ptrs = malloc(sizeof(int *) * arrlen);

  if (!numbers || !ptrs) {
    perror("");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  fill_numbers(numbers, arrlen);
  init_ptr_array(ptrs, arrlen);
  fill_ptr_array(ptrs, numbers, arrlen);

  printf("O maior número do array de ponteiros é %d.\n",
         greatest_of_ptr_array(ptrs, arrlen));

  free_ptr_array(ptrs, arrlen);
  free(numbers);
  return EXIT_SUCCESS;
}

void fill_numbers(int *array, size_t size) {
  for (size_t j = 0; j < size; j++) {
    array[j] = rand_between(1, 100);
  }
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

void fill_ptr_array(int *src_array[], int dest_array[], size_t size) {
  for (size_t k = 0; k < size; k++)
    *src_array[k] = dest_array[k];
}

void init_ptr_array(int *ptr_array[], size_t size) {
  for (size_t i = 0; i < size; i++)
    ptr_array[i] = malloc(sizeof(int *));
}

void free_ptr_array(int *ptr_array[], size_t size) {
  for (size_t l = 0; l < size; l++)
    free(ptr_array[l]);
  free(ptr_array);
}

int greatest_of_ptr_array(int *ptr_array[], size_t size) {
  if (size == 1)
    return *ptr_array[0];

  int greatest = *ptr_array[0];
  for (size_t n = 1; n < size; n++)
    if (*ptr_array[n] > greatest)
      greatest = *ptr_array[n];

  return greatest;
}
