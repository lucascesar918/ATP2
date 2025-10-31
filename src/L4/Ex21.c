#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo> <número>\n",
            argv[0]);
    return 1;
  }

  long target_num = strtol(argv[2], NULL, 10);
  if (target_num > 2147483647L || target_num < -2147483648L) {
    fprintf(stderr, "O número está fora do alcance de um 'int'.\n");
    return 1;
  }
  int target_int = (int)target_num;

  FILE *fd = fopen(argv[1], "rb");
  if (fd == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo %s.\n", argv[1]);
    return 1;
  }

  int int_read;
  size_t bytes_read;

  fseek(fd, 0, SEEK_SET);
  while ((bytes_read = fread(&int_read, sizeof(int), 1, fd)) == 1) {
    if (int_read == target_int) {
      printf("O inteiro %d foi encontrado no arquivo binário!\n", target_int);
      return 0;
    }
    fseek(fd, -(sizeof(int) - 1), SEEK_CUR);
  }

  printf("O inteiro %d não foi encontrado no arquivo binário!\n", target_int);

  fclose(fd);
  return 0;
}