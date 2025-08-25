/*
 * Escreva um programa em C que leia 8 caracteres e verifique
 * quantos são vogais.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_vowel(char ch);
void populate_array(char *array, size_t size);
int count_vowel(char *array, size_t size);
bool is_upper(char ch);

int main(int argc, char *argv[]) {
  const size_t arrlen = 8 + 1;
  char *array = malloc(sizeof(char) * arrlen);

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha na alocação de memória!\n");
    return EXIT_FAILURE;
  }

  populate_array(array, arrlen);
  printf("Digitadas %d vogais.", count_vowel(array, arrlen));

  free(array);
  return EXIT_SUCCESS;
}

bool is_vowel(char ch) {
  if (is_upper(ch))
    ch += 32;
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Função para preencher o array
void populate_array(char *array, size_t size) {
  for (size_t j = 0; j < size - 1; j++) {
    printf("Digite o %zuº caractere: ", j + 1);
    scanf(" %c", array + j);
  }

  array[size - 1] = '\0';
}

int count_vowel(char *array, size_t size) {
  if (size == 0)
    return -1;

  int count = 0;

  for (int i = 0; i < size; i++)
    if (is_vowel(array[i]))
      count++;

  return count;
}

bool is_upper(char ch) { return ch >= 65 && ch <= 90; }
