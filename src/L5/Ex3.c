#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_between(int min, int max);
int recursive_largest_in_array(const int *array, const size_t size);
void populate_array(int *array, const size_t size);
void print_array(const int *array, const size_t size);

int main(int argc, char *argv[]) {
  const size_t arrlen = 10;
  int *arr1 = malloc(sizeof(int) * arrlen);

  srand(time(NULL));

  populate_array(arr1, arrlen);
  print_array(arr1, arrlen);

  printf("O maior valor encontrado no array foi %d\n",
         recursive_largest_in_array(arr1, arrlen));

  free(arr1);
  return EXIT_SUCCESS;
}

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }
int recursive_largest_in_array(const int *array, const size_t size) {
  if (size == 1)
    return array[0];
  if (size == 2)
    return array[0] > array[1] ? array[0] : array[1];

  int n1 = recursive_largest_in_array(array, size / 2);
  int n2 = recursive_largest_in_array(array + (size / 2), size - size / 2);

  return n1 > n2 ? n1 : n2;
}

void populate_array(int *array, const size_t size) {
  for (size_t j = 0; j < size; j++)
    array[j] = rand_between(0, 100);
}

void print_array(const int *array, const size_t size) {
  for (size_t k = 0; k < size; k++)
    printf("[%3zuº]: %3d%c", k + 1, array[k],
           k != 0 && k % 3 == 0 ? '\n' : '\t');
}
