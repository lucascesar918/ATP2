#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recursive_count_pattern(char *src, char *pattern);

int main(int argc, char *argv[]) {
  const size_t bufsize = 1024;
  char *haystack = malloc(sizeof(char) * bufsize);
  char *needle = malloc(sizeof(char) * bufsize);

  if (!haystack || !needle) {
    perror("");
    return EXIT_FAILURE;
  }

  printf("Digite o texto para busca: ");
  fgets(haystack, bufsize, stdin);
  printf("Digite o padrão para busca: ");
  fgets(needle, bufsize, stdin);

  haystack[strcspn(haystack, "\n")] = '\0';
  needle[strcspn(needle, "\n")] = '\0';

  printf(
      "Foram encontradas %d ocorrências do padrão '%s' no texto informado.\n",
      recursive_count_pattern(haystack, needle), needle);

  free(haystack);
  free(needle);
  return EXIT_SUCCESS;
}

int recursive_count_pattern(char *src, char *pattern) {
  int found = 0;
  if (*src == '\0' || strlen(src) < strlen(pattern))
    return 0;

  if (strncmp(src, pattern, strlen(pattern)) == 0)
    return 1 + recursive_count_pattern(src + 1, pattern);

  return recursive_count_pattern(src + 1, pattern);
}
