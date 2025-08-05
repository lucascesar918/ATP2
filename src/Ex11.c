/*
  Escreva um programa em C que preencha um array de 15 inteiros com
  números aleatórios entre 0 e 50. Em seguida, encontre e imprima
  o maior valor do array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int* array, size_t size);
void print_array(int* array, size_t size);
int find_greatest(int* array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 15;
  int* array = malloc(sizeof(int)*arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL)); // Provendo a entropia necessária pra seed com o tempo do computador

  populate_array(array, arrlen);
  printf("O maior valor do array é %d.\n", find_greatest(array, arrlen));

  return EXIT_SUCCESS;
}

// Retorna um aleatório entre um intervalo (inclusivo) mínimo e máximo
int rand_between(int min, int max) {
  return rand() % max + min;
}

// Preenche o array segundo o enunciado
void populate_array(int* array, size_t size) {
  const int minrand = 0, maxrand = 50;

  for (int j=0; j<size; j++)
    array[j] = rand_between(minrand, maxrand);
}

// Maior valor do array em O(n)
int find_greatest(int* array, size_t size) {
  int res = array[0];

  for (int j=1; j<size; j++)
    if (array[j] > res)
      res = array[j];

  return res;
}
