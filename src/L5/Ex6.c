#include <stdio.h>
#include <stdlib.h>

void rev_print(const int *array, const int idx, const size_t size);
void populate_array(int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 50;
  int *arr = malloc(sizeof(int) * arrlen);

  populate_array(arr, arrlen);
  rev_print(arr, 0, arrlen);

  free(arr);
  return EXIT_SUCCESS;
}

void rev_print(const int *array, const int idx, const size_t size) {
  if (idx == size)
    return;

  rev_print(array, idx + 1, size);
  printf("[%2dº]: %3d\n", idx + 1, array[idx]);
}

void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = j + 1;
}
