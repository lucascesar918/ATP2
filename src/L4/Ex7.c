#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr,
            "Argumentos Insuficientes!\nUso: %s <string de busca> <string de "
            "substituição> <arquivo fonte> <arquivo de destino>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  const char *search_pattern = argv[1];
  const char *replace_pattern = argv[2];
  const char *src_filepath = argv[3];
  const char *dest_filepath = argv[4];

  FILE *file = fopen(src_filepath, "r");
  FILE *dest_file = fopen(dest_filepath, "w+");

  if (!file) {
    perror("Erro ao abrir o arquivo");
    return EXIT_FAILURE;
  }

  if (!dest_file) {
    perror("Erro ao criar arquivo temporário");
    return EXIT_FAILURE;
  }

  char ch;
  int match;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == search_pattern[0]) {
      match = 1;
      long current_position = ftell(file);

      for (int i = 1; search_pattern[i] != '\0'; i++) {
        if (fgetc(file) != search_pattern[i]) {
          match = 0;
          break;
        }
      }

      if (match) {
        fputs(replace_pattern, dest_file);
        continue;
      } else {
        fseek(file, current_position, SEEK_SET);
        fputc(ch, file);
      }
    }
    fputc(ch, dest_file);
  }

  fclose(file);
  fclose(dest_file);
  return 0;
}