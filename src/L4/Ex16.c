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

int binary_name_search(GenericStruct *array, size_t size, char *target) {
  if (size == 0)
    return -1;

  int low = 0;
  int high = size - 1;
  int mid;

  while (low <= high) {
    mid = low + ((high - low) / 2);
    int cmp = strcmp(target, array[mid].name);

    if (cmp == 0)
      return mid;

    if (cmp > 0)
      low = mid + 1;

    if (cmp < 0)
      high = mid - 1;
  }

  return -1;
}

void print_registries(GenericStruct *array, size_t size) {
  for (int j = 0; j < size; j++)
    printf("\"%s\", %d anos, %.2fm de altura\n", array[j].name, array[j].age,
           array[j].height);
}

size_t ovewrite_struct_file(FILE *fd, GenericStruct *array, size_t size) {
  return fwrite(array, sizeof(GenericStruct), size, fd);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <registros> <nome para busca>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "r+b");

  if (!fd) {
    perror("Erro ao abrir arquivo para leitura");
    return 1;
  }

  GenericStruct *struct_arr =
      malloc(sizeof(GenericStruct) * MAX_REGISTRIES_STORED);

  if (!struct_arr) {
    perror("Erro ao alocar memória para o buffer");
    fclose(fd);
    return 1;
  }

  int registries_read = file_to_struct_array(fd, struct_arr);
  sort_by_name(struct_arr, registries_read);
  int found_idx = binary_name_search(struct_arr, registries_read, argv[2]);

  if (found_idx == -1) {
    printf("Registro não encontrado!\n");
    free(struct_arr);
    fclose(fd);
    return 1;
  }

  fseek(fd, 0, SEEK_SET);

  printf("Registro encontrado!\n");
  GenericStruct found = struct_arr[found_idx];
  printf("\"%s\", %d anos, %.2fm de altura\n", found.name, found.age,
         found.height);
  swap_registries(&struct_arr[found_idx], &struct_arr[registries_read - 1]);
  registries_read--;
  ovewrite_struct_file(fd, struct_arr, registries_read);
  printf("Registro \"%s\" deletado.\n", found.name);

  free(struct_arr);
  fclose(fd);
  return 0;
}
