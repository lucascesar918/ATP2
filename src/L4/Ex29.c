#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3

void encrypt(FILE *in, FILE *out) {
  int ch;
  while ((ch = fgetc(in)) != EOF) {
    if (ch >= 'a' && ch <= 'z') {
      ch = 'a' + (ch - 'a' + SHIFT) % 26;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = 'A' + (ch - 'A' + SHIFT) % 26;
    }
    fputc(ch, out);
  }
}

void decrypt(FILE *in, FILE *out) {
  int ch;
  while ((ch = fgetc(in)) != EOF) {
    if (ch >= 'a' && ch <= 'z') {
      ch = 'a' + (ch - 'a' - SHIFT + 26) % 26;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = 'A' + (ch - 'A' - SHIFT + 26) % 26;
    }
    fputc(ch, out);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <-e|-d> <arquivo_entrada> "
            "<arquivo_saida>\n",
            argv[0]);
    fprintf(stderr, "  -e: criptografar\n  -d: descriptografar\n");
    return 1;
  }

  char *operation = argv[1];
  char *input_file = argv[2];
  char *output_file = argv[3];

  if (strcmp(operation, "-e") != 0 && strcmp(operation, "-d") != 0) {
    fprintf(stderr, "Operação inválida! Use -e para criptografar ou -d para "
                    "descriptografar\n");
    return 1;
  }

  FILE *in = fopen(input_file, "r");
  FILE *out = fopen(output_file, "w");

  if (!in || !out) {
    fprintf(stderr, "Erro ao abrir o(s) arquivo(s) ");
    if (in)
      fprintf(stderr, "'%s'", output_file);
    else
      fprintf(stderr, "'%s'", input_file);
    fprintf(stderr, "\n");

    if (in)
      fclose(in);
    if (out)
      fclose(out);
    return 1;
  }

  if (strcmp(operation, "-e") == 0)
    encrypt(in, out);
  else
    decrypt(in, out);

  fclose(in);
  fclose(out);
  return 0;
}
