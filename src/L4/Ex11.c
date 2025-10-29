#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  int age;
  double height;
} GenericStruct;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo fonte>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  GenericStruct myStruct;

  size_t bytes_read = fread(&myStruct, sizeof(GenericStruct), 1, fd);

  if (bytes_read < 1) {
    perror("Erro na leitura do arquivo binário");
    return 1;
  }

  printf("Registro lido:\nNome: %s\nIdade: %d\nAltura: %.2f\n", myStruct.name,
         myStruct.age, myStruct.height);

  fclose(fd);
  return 0;
}
