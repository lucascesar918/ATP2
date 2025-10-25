#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 1024 * 1024 * 64 // 64KB para uma boa eficiência na leitura

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos insuficientes!\n\nUso: %s <arquivo fonte> <arquivo de "
            "destino>\n",
            argv[0]);
    return 1;
  }

  FILE *src_file = fopen(argv[1], "rb");
  FILE *dest_file = fopen(argv[2], "wb");

  if (!src_file || !dest_file) {
    perror("Erro ao abrir um dos arquivos");
    if (src_file)
      fclose(src_file);
    if (dest_file)
      fclose(dest_file);
    return 1;
  }

  void *buf = malloc(BLOCKSIZE);

  if (!buf) {
    perror("Erro ao alocar memória para o buffer");
    fclose(src_file);
    fclose(dest_file);
    return 1;
  }

  size_t bytes_read;
  size_t bytes_wrote;

  while ((bytes_read = fread(buf, 1, BLOCKSIZE, src_file))) {
    bytes_wrote = fwrite(buf, 1, bytes_read, dest_file);
    if (bytes_read != bytes_wrote) {
      fprintf(stderr, "Erro na escrita do arquivo.\n");
      break;
    }
  }

  free(buf);
  fclose(src_file);
  fclose(dest_file);
  return 0;
}