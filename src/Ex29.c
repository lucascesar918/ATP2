/*
 * Escreva um programa em C que use um array de ponteiros para
 * armazenar e imprimir 5 strings.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_str_array(char **array, size_t size, size_t string_size);
int populate_array(char **array, size_t size, size_t string_size);
void print_str_array(char **array, size_t size);
void free_str_array(char **array, size_t size);

int main(int argc, char *argv[]) {
  const size_t arrsize = 5;
  const size_t strsize = 1024;

  char **string_array = malloc(sizeof(char **) * arrsize);

  if (!string_array) {
    perror("");
    return EXIT_FAILURE;
  }

  if (init_str_array(string_array, arrsize, strsize)) {
    return EXIT_FAILURE;
  }

  if (populate_array(string_array, arrsize, strsize)) {
    return EXIT_FAILURE;
  }

  printf("\n");
  print_str_array(string_array, arrsize);

  free_str_array(string_array, arrsize);
  free(string_array);
  return EXIT_SUCCESS;
}

int init_str_array(char **array, size_t size, size_t string_size) {
  for (size_t l = 0; l < size; l++) {
    array[l] = malloc(sizeof(char) * string_size);
    if (!array[l]) {
      perror("");
      return 1;
    }
  }

  return 0;
}

int populate_array(char **array, size_t size, size_t string_size) {
  if (!array) {
    perror("");
    return 1;
  }

  for (size_t j = 0; j < size; j++) {
    printf("Digite a %zuª string: ", j + 1);
    fgets(array[j], string_size, stdin);
  }

  return 0;
}

void print_str_array(char **array, size_t size) {
  for (size_t i = 0; i < size; i++)
    printf("[%1zuº]: %s", i + 1, array[i]);
}

void free_str_array(char **array, size_t size) {
  for (size_t k = 0; k < size; k++)
    free(array[k]);
}
