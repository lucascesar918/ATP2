/*
  Escreva um programa em C que preencha um array de 10 inteiros com
  números aleatórios entre 50 e 150. Calcule e imprima a média dos
  elementos do array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
void populate_array(int* array, size_t size);
void print_array(int* array, size_t size);
float array_avg(int* array, size_t size);
int array_summation(int* array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int* array = malloc(sizeof(int)*arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL)); // Provendo a entropia necessária pra seed com o tempo do computador

  populate_array(array, arrlen);
  printf("A média dos valores aleatórios do array resulta em %.1f", array_avg(array, arrlen)); // Não há necessidade de mais que um caractere decimal, pois a precisão não precisa ser tão alta nesse caso (já que a média mínima será 50.0).

  free(array);
  return EXIT_SUCCESS;
}

// Retorna um aleatório entre um intervalo (inclusivo) mínimo e máximo
int rand_between(int min, int max) {
  return rand() % max + min;
}

// Preenche o array segundo o enunciado
void populate_array(int* array, size_t size) {
  const int minrand = 50, maxrand = 150;

  for (int j=0; j<size; j++)
    array[j] = rand_between(minrand, maxrand);
}

float array_avg(int* array, size_t size) {
  return (float) array_summation(array, size) / (float) size;
}

int array_summation(int* array, size_t size) {
  int sum = 0;

  for (int j=0; j<size; j++)
       sum += array[j];

  return sum;
}
