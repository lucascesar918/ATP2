#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Argumentos insuficientes!\n\nUso: %s [arquivo] [caractere]\n",
           argv[0]);
    return 1;
  }

  FILE *haystack = fopen(argv[1], "r");
  char needle = argv[2][0];
  char ch;
  int line = 1, col = 1;

  while ((ch = fgetc(haystack)) && ch != EOF) {
    if (ch == '\n') {
      col = 1;
      line++;
    }

    if (ch == needle) {
      printf("Caractere encontrado pela primeira vez na linha %d, coluna %d.\n",
             line, col);
      return 0;
    }

    col++;
  }

  printf("Caractere não encontrado no arquivo.\n");

  fclose(haystack);
  return 1;
}