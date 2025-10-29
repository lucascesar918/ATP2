#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 1024 * 64
#define MAX_REGISTRIES_STORED 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

void swap_registries(GenericStruct *a, GenericStruct *b) {
  GenericStruct aux = *a;
  *a = *b;
  *b = aux;
}

int file_to_struct_array(FILE *file, GenericStruct *array) {
  size_t items_read =
      fread(array, sizeof(GenericStruct), MAX_REGISTRIES_STORED, file);

  return items_read;
}

void sort_by_height(GenericStruct *array, size_t size) {
  int idx_low;

  for (int idx_unsorted = 0; idx_unsorted < size; idx_unsorted++) {
    idx_low = idx_unsorted;
    for (int j = idx_unsorted; j < size; j++)
      if (array[j].height < array[idx_low].height)
        idx_low = j;

    swap_registries(&array[idx_unsorted], &array[idx_low]);
  }
}

void sort_by_name(GenericStruct *array, size_t size) {
  int idx_low;

  for (int idx_unsorted = 0; idx_unsorted < size; idx_unsorted++) {
    idx_low = idx_unsorted;
    for (int j = idx_unsorted; j < size; j++)
      if (strcmp(array[j].name, array[idx_low].name) < 0)
        idx_low = j;

    swap_registries(&array[idx_unsorted], &array[idx_low]);
  }
}

void print_registries(GenericStruct *array, size_t size) {
  for (int j = 0; j < size; j++)
    printf("\"%s\", %d anos, %.2fm de altura\n", array[j].name, array[j].age,
           array[j].height);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <registros>\n", argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    perror("Erro ao abrir arquivo para leitura");
    return 1;
  }

  GenericStruct *struct_arr =
      malloc(sizeof(GenericStruct) * MAX_REGISTRIES_STORED);

  if (!struct_arr) {
    perror("Erro ao alocar memória para o buffer");
    free(struct_arr);
    fclose(fd);
    return 1;
  }

  int registries_read = file_to_struct_array(fd, struct_arr);
  printf("Foram lidos %d registros:\n", registries_read);
  print_registries(struct_arr, registries_read);

  printf("\nOrdenando por altura...\n");
  sort_by_height(struct_arr, registries_read);
  print_registries(struct_arr, registries_read);

  printf("\nOrdenando por nome...\n");
  sort_by_name(struct_arr, registries_read);
  print_registries(struct_arr, registries_read);

  free(struct_arr);
  fclose(fd);
  return 0;
}
