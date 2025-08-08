/*
  Escreva um programa em C que preencha um array de 12 inteiros com
  números aleatórios entre -20 e 20. Em seguida, conte e imprima
  quantos números são negativos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int* array, size_t size);
void print_array(int* array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int* array = malloc(sizeof(int)*arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL)); // Provendo a entropia necessária pra seed com o tempo do computador

  populate_array(array, arrlen);
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

// Retorna um aleatório entre um intervalo (inclusivo) mínimo e máximo
int rand_between(int min, int max) {
  return rand() % (max - min + 1) + min; // Aumentando a amplitude da cobertura da função e depois considerando os valores de -20 a -1.
}

// Preenche o array segundo o enunciado
void populate_array(int* array, size_t size) {
  const int minrand = -20, maxrand = 20;

  for (int j=0; j<size; j++)
    array[j] = rand_between(minrand, maxrand);
}

void print_array(int* array, size_t size) {
  int i=0, c=1;

  while (i<size) {
    if (array[i] < 0){
      if (c % 3 == 0)
        printf("[%2dº]: %3d\n", c++, array[i]);
      else
        printf("[%2dº]: %3d\t", c++, array[i]);
    }
    i++;
  }
}
