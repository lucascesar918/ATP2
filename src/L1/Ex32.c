/*
 * Escreva um programa em C que use um array de ponteiros
 * para armazenar 4 strings e encontre a string de maior comprimento.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_ptr_array(char *array[], size_t size);
void fill_ptr_array(char *array[], size_t size, size_t str_size);
char *find_largest_str(char *array[], size_t size);
void trim_newline(char *str);

int main(int argc, char *argv[]) {
  const size_t arrlen = 4;
  const size_t strsize = 1024;
  char **ptr_array = malloc(sizeof(char *) * arrlen);

  fill_ptr_array(ptr_array, arrlen, strsize);
  putchar('\n');
  printf("A maior string digitada foi '%s'.\n",
         find_largest_str(ptr_array, arrlen));

  free(ptr_array);
  return EXIT_SUCCESS;
}

void free_ptr_array(char *array[], size_t size) {
  for (size_t j = 0; j < size; j++)
    free(array[j]);

  free(array);
}

void fill_ptr_array(char *array[], size_t size, size_t str_size) {
  for (size_t k = 0; k < size; k++) {
    array[k] = malloc(sizeof(char *) * str_size);
    printf("Digite a %zuª string: ", k + 1);
    fgets(array[k], str_size, stdin);
    trim_newline(array[k]);
  }
}

char *find_largest_str(char *array[], size_t size) {
  if (size == 1)
    return array[0];

  size_t largest_len = strlen(array[0]);
  char *largest = array[0];

  for (size_t l = 0; l < size; l++) {
    if (largest_len < strlen(array[l])) {
      largest_len = strlen(array[l]);
      largest = array[l];
    }
  }

  return largest;
}

void trim_newline(char *str) {
  size_t index = strrchr(str, '\n') - str;
  if (str[index] == '\n')
    str[index] = '\0';
}
