#include <stdio.h>
#include <stdlib.h>

int compress(FILE *in, FILE *out) {
  int count = 1;
  char last_ch = '\0';
  int ch;

  while ((ch = fgetc(in)) != EOF) {
    if (last_ch != (char)ch) {
      if (last_ch == '\0') {
        last_ch = (char)ch;
        continue;
      }
      fprintf(out, "%d%c", count, last_ch);
      last_ch = (char)ch;
      count = 1;
      continue;
    }

    count++;
  }

  if (ch == EOF && last_ch != '\0')
    fprintf(out, "%d%c", count, last_ch);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  FILE *file = fopen(filename, "rb");

  char *outname = "compressed.rle";
  FILE *out = fopen(outname, "wb");

  if (!file || !out) {
    fprintf(stderr, "Erro ao abrir o(s) arquivo(s) ");
    if (file)
      fprintf(stderr, "'%s'", outname);
    else
      fprintf(stderr, "'%s'", filename);
    fprintf(stderr, "\n");

    if (file)
      fclose(file);
    if (out)
      fclose(out);
    return 1;
  }

  compress(file, out);

  fclose(file);
  fclose(out);
  return 0;
}