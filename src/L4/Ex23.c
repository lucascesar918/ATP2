#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTRIES_STORED 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

int registry_linear_search(GenericStruct *struct_array, int size,
                           char reg_name[MAX_NAME_LENGTH]) {
  for (int j = 0; j < size; j++)
    if (strcmp(struct_array[j].name, reg_name) == 0)
      return j;

  return -1;
}

int get_registry_offset(FILE *file, GenericStruct *struct_array, int size,
                        char reg_name[MAX_NAME_LENGTH]) {
  int reg_idx = registry_linear_search(struct_array, size, reg_name);
  return reg_idx < 0 ? reg_idx : reg_idx * sizeof(GenericStruct);
}

int file_to_struct_array(FILE *file, GenericStruct *array) {
  size_t items_read =
      fread(array, sizeof(GenericStruct), MAX_REGISTRIES_STORED, file);

  return items_read;
}

void print_registries(GenericStruct *array, size_t size) {
  for (int j = 0; j < size; j++)
    printf("\"%s\", %d anos, %.2fm de altura\n", array[j].name, array[j].age,
           array[j].height);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <registros> <nome para busca>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");
  char *search_name = argv[2];

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
  int offset =
      get_registry_offset(fd, struct_arr, registries_read, search_name);

  if (offset < 0)
    printf("Registro não encontrado!\n");
  else
    printf("O offset do registro '%s' é 0x%x\n", search_name, offset);

  free(struct_arr);
  fclose(fd);
  return 0;
}
