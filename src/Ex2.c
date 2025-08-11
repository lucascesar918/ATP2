#include <stdio.h>
#include <stdlib.h>

void populate_array(char *array, size_t size, char base_char);
void print_array(char *array, size_t size);

int main(int argc, char **argv) {
  const size_t arrlen = 5;
  char *array = malloc(arrlen * sizeof(char));

  // Checando falha de alocação de memória
  if (array == NULL) {
    perror("Falha ao alocar memória para o array!\n");
    free(array);
    return EXIT_FAILURE;
  }

  const char base_char = 'a';

  populate_array(array, arrlen, base_char);
  print_array(array, arrlen);

  free(array);
  return 0;
}

// Função para preencher o array
void populate_array(char *array, size_t size, char base_char) {
  for (size_t j = 0; j < size; j++)
    array[j] = base_char + j;
}

// Função para printar os valores do array
void print_array(char *array, size_t size) {
  for (size_t c = 0; c < size; c++)
    printf("[%2.zu°]: %c\n", c + 1, array[c]);
}
