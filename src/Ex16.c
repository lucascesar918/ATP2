/*
  Escreva um programa em C que declare um array de 10
  caracteres e use um ponteiro para contar quantos desses
  caracteres são letras maiúsculas.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(char *array, size_t size);
bool is_upper(char ch);
int rand_between(int min, int max);
char rand_char();
int count_upper(char *array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  char *array = malloc(sizeof(char) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  printf("De todos os %zu caracteres do array, %d são maiúsculos\n", arrlen,
         count_upper(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(char *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_char();
}

bool is_upper(char ch) { return ch >= 65 && ch <= 90; }

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

char rand_char() {
  return rand_between(0, 1) ? rand_between(65, 90) : rand_between(97, 122);
}

int count_upper(char *array, size_t size) {
  int upper_count = 0;
  for (int c = 0; c < size; c++)
    if (is_upper(*(array + c)))
      upper_count++;

  return upper_count;
}
