/*
  Escreva um programa em C que verifique se todos os elementos
  de um array de 5 inteiros são positivos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(int *array, const size_t size);
void print_array(const int *array, const size_t size);
int rand_between(const int min, const int max);
int is_all_positive(const int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 5;
  int *array = malloc(sizeof(int) * arrlen);

  if (!array) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  print_array(array, arrlen);
  printf("%s os números do array são positivos\n",
         is_all_positive(array, arrlen) ? "Todos" : "Nem todos");

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(-1, 10);
}

void print_array(const int *array, const size_t size) {
  putchar('{');
  for (int j = 0; j < size; j++) {
    printf("%2d", *(array + j));
    if (j != size - 1)
      printf(", ");
  }
  printf("}\n");
}

int rand_between(const int min, const int max) {
  return rand() % (max - min + 1) + min;
}

int is_all_positive(const int *array, const size_t size) {
  int count = 0;

  for (int c = 0; c < size; c++)
    if (array[c] > 0)
      count++;

  return count == size;
}
