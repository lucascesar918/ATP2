/*
  Escreva um programa em C que leia 10 valores inteiros e
  calcule a soma de todos os elementos do array.
*/
#include <stdio.h>
#include <stdlib.h>

void populate_array(int* array, size_t size);
int array_summation(int* array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int* array = malloc(sizeof(int)*arrlen);

  // Checando falha de alocação de memória
  if (array == NULL){
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);

  printf("A soma dos números do array resulta em %d.\n", array_summation(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

// Função para preencher o array
void populate_array(int* array, size_t size) {
  for (int j=0; j<size; j++){
    printf("Digite o %dº número: ", j+1);
    scanf("%d", &array[j]);
  }
}

int array_summation(int* array, size_t size) {
  int sum = 0;

  for (int j=0; j<size; j++)
       sum += array[j];

  return sum;
}
