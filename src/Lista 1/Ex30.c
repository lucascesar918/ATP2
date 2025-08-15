/*
 * Escreva um programa em C que use um array de ponteiros para armazenar 3
 * strings, ordene as strings em ordem alfabética e as imprima.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_str_array(char **array, size_t size, size_t string_size);
int populate_array(char **array, size_t size, size_t string_size);
void print_str_array(char **array, size_t size);
void free_str_array(char **array, size_t size);
void order_str_array(char **array, size_t size);
void compare_and_swap_str(char **str1, char **str2);
void swap_strings(char **str1, char **str2);

int main(int argc, char *argv[]) {
  const size_t arrsize = 3;
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
  order_str_array(string_array, arrsize);
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

void order_str_array(char **array, size_t size) {
  compare_and_swap_str(&array[0], &array[1]);
  compare_and_swap_str(&array[1], &array[2]);
  compare_and_swap_str(&array[0], &array[1]);
}

void compare_and_swap_str(char **str1, char **str2) {
  if (strcmp(*str1, *str2) > 0) {
    swap_strings(str1, str2);
  }
}

void swap_strings(char **str1, char **str2) {
  char *aux = *str1;

  *str1 = *str2;
  *str2 = aux;
}
