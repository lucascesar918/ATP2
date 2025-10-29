#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <arquivo> <nome do "
            "registro> <idade do registro> <altura do registro>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "ab");

  if (!fd) {
    perror("Erro ao abrir arquivo para escrita");
    return 1;
  }

  GenericStruct registry;

  strcpy(registry.name, argv[2]);
  registry.age = atoi(argv[3]);
  registry.height = atof(argv[4]);

  size_t bytes_wrote = fwrite(&registry, sizeof(GenericStruct), 1, fd);

  if (bytes_wrote < 1) {
    perror("Erro na escrita de arquivo");
    fclose(fd);
    return 1;
  }

  printf("Escrita realizada com sucesso!\n");

  fclose(fd);
  return 0;
}
