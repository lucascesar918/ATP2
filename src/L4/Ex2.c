#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RBUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos insuficientes\n\nUso: %s <arquivo fonte>\n",
            argv[0]);
    return 1;
  }

  const char *filename = argv[1];
  char *rbuf = malloc(sizeof(char) * RBUFSIZE);
  FILE *fp = fopen(filename, "r");

  if (!fp) {
    printf("Não foi possível abrir o arquivo.\n");
    return 1;
  }

  while (fgets(rbuf, RBUFSIZE, fp))
    printf("%s\n", rbuf);

  free(rbuf);
  fclose(fp);
  return 0;
}