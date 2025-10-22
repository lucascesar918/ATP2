#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 16

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos insuficientes!\n\nUso: %s <arquivo fonte>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    perror("Falha ao ler arquivo");
    return 1;
  }

  char *buf = malloc(CHUNK_SIZE);

  if (!buf) {
    perror("Erro ao alocar memória para o buffer");
    return 1;
  }

  long long offset = 0;
  size_t bytes_read;

  while ((bytes_read = fread(buf, 1, CHUNK_SIZE, fd))) {
    printf("%016llx: ", offset);
    int i;
    for (i = 0; i < CHUNK_SIZE; i++) {
      if (i < bytes_read)
        printf("%02x ", (unsigned char)buf[i]);
      else
        printf("   ");

      if (i == 7)
        printf("  ");
    }
    printf("    | ");
    for (i = 0; i < CHUNK_SIZE; i++) {
      if (i < bytes_read) {
        if (buf[i] >= 32 && buf[i] <= 126)
          printf("%c", buf[i]);
        else
          putchar('.');
      }
    }

    printf("\n");

    offset += bytes_read;
  }

  printf("\n\n");

  free(buf);
  fclose(fd);
  return 0;
}
