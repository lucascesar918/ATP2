/*
  Escreva um programa em C que leia 6 valores de ponto flutu-
  ante e calcule a média dos valores. 
*/
#include <stdio.h>
#include <stdlib.h>

void populate_array(float* array, size_t size);


float array_avg(float* array, size_t size);
float array_summation(float* array, size_t size);

int main(int argc, char *argv[])
{
  const size_t arrlen = 6;
  float* array = malloc(sizeof(float)*arrlen);

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha na alocação de memória!\n");
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);
  printf("A média dos números do array resulta em %.2f\n", array_avg(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

// Função para preencher o array
void populate_array(float* array, size_t size) {
  for (int j=0; j<size; j++) {
    printf("Digite o %dº número: ", j+1);
    scanf("%f", &array[j]);
  }
}

float array_avg(float* array, size_t size) {
  return array_summation(array, size) / (float)(size);
}

float array_summation(float* array, size_t size) {
  float sum = 0.0;

  for (int j=0; j<size; j++)
       sum += array[j];

  return sum;
}
