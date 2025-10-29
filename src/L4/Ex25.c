#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 256
#define WIDTH 256
#define MAXVAL 255

int main() {
  FILE *fp = fopen("gradient.ppm", "w");

  if (!fp) {
    perror("Falha ao abrir o arquivo.\n");
    return 1;
  }

  /* Escrevendo a header do arquivo .ppm */
  fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAXVAL);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      unsigned char r = (unsigned char)j;
      unsigned char g = (unsigned char)i;
      unsigned char b = (unsigned char)(255 - (i / 2 + j / 2));

      unsigned char pixel[3] = {r, g, b};
      if (fwrite(pixel, 1, 3, fp) != 3) {
        fprintf(stderr, "Erro escrevendo no arquivo!\n");
        fclose(fp);
        return 1;
      }
    }
  }

  fclose(fp);
  printf("Arquivo .ppm gerado com sucesso!\n");

  return 0;
}