/*
* Escreva um programa em C que leia 8 caracteres e verifique
* quantos são vogais.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_vowel(char ch);
void populate_array(char* array, size_t size);

int main(int argc, char *argv[])
{
  const size_t arrlen = 8+1;
  char* array = malloc(sizeof(char)*arrlen);

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha na alocação de memória!\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

bool is_vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Função para preencher o array
void populate_array(char* array, size_t size) {
  for (int j=0; j<size; j++) {}
}
