/*
  Escreva um programa em C que declare um array de 8 números de
  ponto flutuante e use aritmética de ponteiros para calcular a média
  dos valores.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate_array(float *array, size_t size);
float rand_float_between(int min, int max);
float array_avg(float *array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 8;
  float *array = malloc(sizeof(float) * arrlen);

  if (array == NULL) {
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  srand(time(NULL));

  populate_array(array, arrlen);
  printf("A média aritmética dos elementos do array resulta em %.4f.",
         array_avg(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

void populate_array(float *array, size_t size) {
  for (int j = 0; j < size; j++)
    *(array + j) = rand_float_between(-100, 100);
}

float rand_float_between(int min, int max) {
  return (rand() % (max - min + 1) + min) / 10.0;
}

float array_avg(float *array, size_t size) {
  float sum = 0.0;

  for (int j = 0; j < size; j++)
    sum += *(array + j);

  return sum / size;
}
