#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LINE_EXPECTED_LENGTH 1024 * 4

void trim_newline(char *str, ssize_t len) {
  if (str[len - 1] == '\n' && len > 0)
    str[len - 1] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr,
            "Argumentos inválidos!\n\nUso: %s <arquivo base> <arquivo "
            "secundário>\n",
            argv[0]);
    return 1;
  }

  char *basefilename = argv[1];
  char *secfilename = argv[2];
  FILE *basefile = fopen(basefilename, "r");
  FILE *secfile = fopen(secfilename, "r");

  if (!basefile || !secfile) {
    fprintf(stderr, "Erro ao abrir arquivo(s) ");
    if (basefile) {
      fclose(basefile);
      fprintf(stderr, "%s", secfilename);
    }
    if (secfile) {
      fclose(secfile);
      fprintf(stderr, "%s", basefilename);
    }
    fprintf(stderr, "\n");
    return 1;
  }

  char *basebuf = NULL;
  char *secbuf = NULL;
  ssize_t baseread = 0;
  ssize_t secread = 0;

  while (1) {
    baseread = getline(&basebuf, &(size_t){baseread}, basefile);
    secread = getline(&secbuf, &(size_t){secread}, secfile);

    if (baseread < 0 && secread < 0)
      break;

    trim_newline(basebuf, strlen(basebuf));
    trim_newline(secbuf, strlen(secbuf));

    if (strlen(basebuf) == 0 && strlen(secbuf) == 0)
      continue;

    int is_equal = strcmp(basebuf, secbuf) == 0;

    if (is_equal)
      printf("= %s\n", basebuf);
    else
      printf("\n- %s\n+ %s\n", basebuf, secbuf);
  }

  free(basebuf);
  free(secbuf);
  fclose(basefile);
  fclose(secfile);
  return 0;
}