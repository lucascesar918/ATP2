#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: <arquivo> <palavra de busca>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");

  if (!fd) {
    fprintf(stderr, "Falha ao abrir o arquivo %s\n", argv[1]);
    return 1;
  }

  const char *search_word = argv[2];
  int char_read;
  long latest_pos = 0;
  int match = 0;
  int count = 0;

  while ((char_read = fgetc(fd)) != EOF) {
    if (char_read == search_word[0]) {
      match = 1;
      latest_pos = ftell(fd);

      for (int j = 1; search_word[j] != '\0'; j++)
        if (fgetc(fd) != search_word[j]) {
          match = 0;
          break;
        }

      if (match)
        count++;
      else
        fseek(fd, latest_pos, SEEK_SET);
    }
  }

  printf("A string '%s' foi encontrada %d vezes no arquivo!\n", search_word,
         count);

  fclose(fd);
  return 0;
}
