#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 1024 * 64 // 64 KB para boa eficiência de leitura e escrita

int copy_to_file(FILE *src_file, FILE *dest_file) {
  size_t bytes_read;
  size_t bytes_written;

  void *buf = malloc(BLOCKSIZE);

  if (!buf)
    return 1;

  while ((bytes_read = fread(buf, 1, BLOCKSIZE, src_file)) > 0) {
    bytes_written = fwrite(buf, 1, bytes_read, dest_file);
    if (bytes_written < bytes_read) {
      free(buf);
      return 1;
    }
  }

  free(buf);

  if (ferror(src_file))
    return 1;

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: <arquivo fonte> <arquivo fonte> "
            "<arquivo de destino>\n",
            argv[0]);
    return 1;
  }

  FILE *fd_a = fopen(argv[1], "rb");
  FILE *fd_b = fopen(argv[2], "rb");
  /* ab não faria sentido no lugar de wb, pois concatenaria dois arquivos com
   * um terceiro possivelmente já existente*/
  FILE *fd_c = fopen(argv[3], "wb");

  if (!fd_a || !fd_b || !fd_c) {
    perror("Falha ao abrir um dos arquivos");
    if (fd_a)
      fclose(fd_a);
    if (fd_b)
      fclose(fd_b);
    if (fd_c)
      fclose(fd_c);

    return 1;
  }

  if (copy_to_file(fd_a, fd_c) || copy_to_file(fd_b, fd_c)) {
    perror("Erro ao concatenar arquivos");
    return 1;
  }

  printf("Concatenação realizada com sucesso.\n");

  fclose(fd_a);
  fclose(fd_b);
  fclose(fd_c);
  return 0;
}
