/*
  Escreva um programa em C que preencha um array de 20 inteiros
  com números aleatórios entre 1 e 100. Em seguida, imprima todos os elementos
  do array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int *array, size_t size);
void print_array(int *array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 20;
  int *array = malloc(sizeof(int) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL)); // Provendo a entropia necessária pra seed com o tempo do
                     // computador

  populate_array(array, arrlen);
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

// Retorna um aleatório entre um intervalo (inclusivo) mínimo e máximo
int rand_between(int min, int max) { return rand() % max + min; }

// Preenche o array segundo o enunciado
void populate_array(int *array, size_t size) {
  const int minrand = 1, maxrand = 100;

  for (int j = 0; j < size; j++)
    array[j] = rand_between(minrand, maxrand);
}

// Printa os valores do array de forma intuitiva e legível em colunas
void print_array(int *array, size_t size) {
  for (int i = 0; i < size; i++) {
    if ((i + 1) % 5 == 0)
      printf("[%2dº]: %3d\n", i + 1, array[i]);
    else
      printf("[%2dº]: %3d\t", i + 1, array[i]);
  }
}
