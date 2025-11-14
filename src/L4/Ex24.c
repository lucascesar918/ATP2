#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_REGISTRIES_STORED 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

int rand_between(int min, int max) { return rand() % (max - min + 1) + min; }

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
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <registros>\n", argv[0]);
    return 1;
  }

  srand(time(NULL));
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
  print_registries(struct_arr + rand_between(0, registries_read - 1), 1);

  free(struct_arr);
  fclose(fd);
  return 0;
}
