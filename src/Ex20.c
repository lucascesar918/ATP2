/*
  Escreva um programa em C que declare um array de 12
  caracteres e use aritmética de ponteiros para inverter
  a ordem dos caracteres no array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(char *array, size_t size);
void print_array(char *array, size_t size);
char rand_char();
void invert_array(char *array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 12;
  char *array = malloc(sizeof(char) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    free(array);
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  printf("Antes de inverter:\n");
  print_array(array, arrlen);

  invert_array(array, arrlen);
  printf("\nDepois de inverter:\n");
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(char *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_char();
}

void print_array(char *array, size_t size) {
  putchar('{');
  for (int j = 0; j < size; j++) {
    printf("%3d", *(array + j));
    if (j != size - 1)
      printf(", ");
  }
  printf("}\n");
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

char rand_char() {
  return rand_between(0, 1) ? rand_between(65, 90) : rand_between(97, 122);
}

void invert_array(char *array, size_t size) {
  size_t j = 0, k = size - 1;
  char aux;

  while (k > j) {
    aux = *(array + j);
    *(array + j++) = *(array + k);
    *(array + k--) = aux;
  }
}
