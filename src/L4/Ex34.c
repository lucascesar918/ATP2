#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(char *prog) {
  fprintf(stderr, "Argumentos inválidos!\n\nUso:\n");
  fprintf(stderr, "\t%s [OPÇÃO] [ARQUIVOS]", prog);
  fprintf(stderr, "\nFlags:\n");
  fprintf(stderr,
          "\t-c, --check <arquivo> <checkum>\t\t# Checa se o arquivo bate com o "
          "checksum fornecido.\n");
  fprintf(stderr,
          "\t-g, --generate <arquivo> <checksum>\t# Gera o checksum do arquivo "
          "e armazena no diretório informado.\n");
}

int get_sum(char *filepath, uint64_t *out) {
  uint64_t sum = 0;
  int c;
  FILE *fd = fopen(filepath, "rb");

  if (!fd)
    return 1;

  while ((c = fgetc(fd)) != EOF)
    sum += (unsigned char)c;

  fclose(fd);
  return 0;
}

int read_sum(char *filepath, uint64_t *out) {
  FILE *fd = fopen(filepath, "rb");
  if (!fd)
    return 1;

  if (fread(out, sizeof(uint64_t), 1, fd) <= 0) {
    fclose(fd);
    return 1;
  }

  fclose(fd);
  return 0;
}

int write_sum(char *filepath, uint64_t sum) {
  FILE *fd = fopen(filepath, "wb");
  if (!fd)
    return 1;

  if (fwrite(&sum, sizeof(uint64_t), 1, fd) < 1) {
    fclose(fd);
    return 1;
  }

  fclose(fd);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    usage(argv[0]);
    return 1;
  }

  char *filepath = argv[2];
  char *sumfilepath = argv[3];
  uint64_t file_checksum;

  if (!strcmp(argv[1], "--check") || !strcmp(argv[1], "-c")) {
    uint64_t expected_checksum;
    if (get_sum(filepath, &file_checksum) ||
        read_sum(sumfilepath, &expected_checksum)) {
      fprintf(stderr, "Erro ao ler o(s) arquivo(s).\n");
      return 1;
    }

    if (file_checksum == expected_checksum)
      printf("O arquivo está de acordo com o checksum.\n");
    else
      printf("O arquivo não está de acordo com o checksum.\n");
  } else if (!strcmp(argv[1], "--generate") || !strcmp(argv[1], "-g")) {
    get_sum(filepath, &file_checksum);
    write_sum(sumfilepath, file_checksum);
  } else {
    usage(argv[0]);
    return 1;
  }
  return 0;
}