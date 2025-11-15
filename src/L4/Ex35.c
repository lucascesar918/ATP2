#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(char *prog) {
  fprintf(stderr, "Argumentos inválidos!\n\n");
  fprintf(stderr, "Uso:\n\t%s [ARQUIVO]\n\n", prog);
}

int count_chars(char *filepath, int count_arr[]) {
  FILE *fd = fopen(filepath, "r");
  int ch;

  if (!fd)
    return 1;

  while ((ch = fgetc(fd)) != EOF)
    count_arr[(unsigned char) ch]++;

  fclose(fd);
  return 0;
}

static void print_count_array(int count_arr[]){
  for (size_t i = 0; i<=255; i++)
    if (count_arr[i] != 0)
      printf("%1c: %d\n", (char) i, count_arr[i]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage(argv[0]);
    return 1;
  }

  char *filepath = argv[1];
  int count[256] = {0};

  if (count_chars(filepath, count))
    perror("Erro ao ler arquivo");

  print_count_array(count);

  return 0;
}
