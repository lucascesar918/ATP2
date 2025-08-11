/*
  Escreva um programa em C que determine se um array de
  10 inteiros é simétrico (um palíndromo)
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, size_t size);
void print_array(int *array, size_t size);
bool is_palindrome(int *array, size_t size);
int rand_between(int min, int max);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  print_array(array, arrlen);
  printf("O array %s palíndromo!\n",
         is_palindrome(array, arrlen) ? "é" : "não é");

  /*
  // Teste em massa para achar um array palíndromo aleatoriamente
  while (!is_palindrome(array, arrlen)) {
    populate_array(array, arrlen);
    print_array(array, arrlen);

    printf("O array %s palíndromo!\n",
           is_palindrome(array, arrlen) ? "é" : "não é");
  }
  */

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(-1, 1);
}

void print_array(int *array, size_t size) {
  putchar('{');
  for (int j = 0; j < size; j++) {
    printf("%2d", *(array + j));
    if (j != size - 1)
      printf(", ");
  }
  printf("}\n");
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

bool is_palindrome(int *array, const size_t size) {
  size_t k = size - 1;

  for (size_t i = 0; i < size && k > i; i++)
    if (array[i] != array[k--])
      return false;

  return true;
}
