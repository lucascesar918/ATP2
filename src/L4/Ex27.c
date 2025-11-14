#include <stdio.h>
#include <stdlib.h>

#define FILENAME_BUFSIZE 50

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <tamanho dos blocos> <arquivo>\n",
            argv[0]);
    return 1;
  }

  const char *suffix = ".chunk";
  char *endptr;
  const long blocksize = strtol(argv[1], &endptr, 10);
  if (blocksize <= 0 || *endptr != '\0' || endptr == argv[1])
    return 1;

  char *filename = argv[2];
  FILE *file = fopen(filename, "rb");

  if (!file) {
    perror("Erro ao abrir arquivo para leitura");
    return 1;
  }

  char *outfilename = malloc(FILENAME_BUFSIZE);
  if (!outfilename) {
    perror("Erro ao alocar memória para o buffer");
    return 1;
  }

  int filecount = 1;

  size_t bytes_written;
  size_t bytes_read;
  void *buf = malloc(blocksize);

  if (!buf || !outfilename) {
    perror("Erro ao alocar memória para o buffer");
    if (buf)
      free(buf);
    if (outfilename)
      free(outfilename);
    fclose(file);
    return 1;
  }

  while ((bytes_read = fread(buf, 1, blocksize, file)) > 0) {
    snprintf(outfilename, FILENAME_BUFSIZE, "%03X.chunk", filecount++);
    FILE *out = fopen(outfilename, "wb");
    if (!out) {
      perror("Erro ao abrir arquivo para escrita");
      fclose(file);
      free(outfilename);
      free(buf);
      return 1;
    }
    bytes_written = fwrite(buf, 1, bytes_read, out);
    if (bytes_written != bytes_read) {
      perror("Erro ao escrever no arquivo de saída");
      fclose(out);
      break;
    }
    fclose(out);
  }

  free(buf);
  free(outfilename);
  fclose(file);
  return 0;
}
