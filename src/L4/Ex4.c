#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos insuficientes!\n\nUso: %s <arquivo fonte> <arquivo de "
            "destino>\n",
            argv[0]);
    return 1;
  }

  FILE *src_fp = fopen(argv[1], "r");
  FILE *dest_fp = fopen(argv[2], "w");

  if (!src_fp || !dest_fp) {
    perror("Erro ao abrir um dos arquivos.");
    return 1;
  }

  char ch;

  while ((ch = fgetc(src_fp)) && ch != EOF)
    fputc(ch, dest_fp);

  fclose(src_fp);
  fclose(dest_fp);

  return 0;
}