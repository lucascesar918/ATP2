/*
Escreva um programa em C que leia 5 valores inteiros, armazene-
os em um array e depois imprima os valores na ordem inversa.
*/
#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, size_t size);
void populate_array(int* array, size_t size);

int main(int argc, char *argv[])
{
  const size_t arrlen = 5;
  int* array = malloc(sizeof(int)*arrlen);

  // Checando falha de alocação de memória
  if (array == NULL){
    perror("Falha ao alocar memória!\n");
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);
  printf("\n");
  print_array(array, arrlen);

  free(array);
  return EXIT_SUCCESS;
}

// Função para printar os valores do array
void print_array(int* array, size_t size){
  for (int j=size-1; j>=0; j--)
    printf("[%dº]: %d\n", j+1, array[j]);
}

// Função para preencher o array
void populate_array(int* array, size_t size){
  for (int j=0; j<size; j++){
    printf("Digite o %dº número: ", j+1);
    scanf("%d", &array[j]);
  }
}
