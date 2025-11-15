#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Compilar usando a flag -lm no GCC pra linkar a biblioteca math

typedef struct {
  float min;
  float max;
  float mean;
  float std_dev;
  long count;
  double sum;
  double sum_sq;
} Statistics;

static long count_values(FILE *fd) {
  long current_pos = ftell(fd);
  fseek(fd, 0, SEEK_END);
  long fsize = ftell(fd);
  fseek(fd, current_pos, SEEK_SET);
  return fsize / sizeof(float);
}

static void calculate_statistics(FILE *fd, Statistics *stats) {
  fseek(fd, 0, SEEK_SET);
  float value;
  stats->count = 0;
  stats->sum = 0;
  stats->sum_sq = 0;
  stats->min = 1e9;
  stats->max = -1e9;

  while (fread(&value, sizeof(float), 1, fd) == 1) {
    stats->count++;
    stats->sum += value;
    stats->sum_sq += value * value;

    if (value < stats->min)
      stats->min = value;
    if (value > stats->max)
      stats->max = value;
  }

  if (stats->count > 0) {
    stats->mean = (float)(stats->sum / stats->count);
    double variance = (stats->sum_sq / stats->count) - (stats->mean * stats->mean);
    stats->std_dev = (float)sqrt(variance);
  } else {
    stats->mean = 0;
    stats->std_dev = 0;
  }
}

static void print_statistics(Statistics *stats) {
  printf("\nEstatísticas do arquivo binário:\n");
  printf("========================================\n");
  printf("Total de valores: %ld\n", stats->count);
  printf("Mínimo: %.6f\n", stats->min);
  printf("Máximo: %.6f\n", stats->max);
  printf("Média: %.6f\n", stats->mean);
  printf("Desvio padrão: %.6f\n", stats->std_dev);
  printf("Soma: %.6f\n", stats->sum);
  printf("========================================\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo_binário>\n",
            argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", argv[1]);
    return 1;
  }

  long value_count = count_values(fd);
  if (value_count == 0) {
    fprintf(stderr, "O arquivo está vazio ou não contém dados válidos\n");
    fclose(fd);
    return 1;
  }

  Statistics stats;
  calculate_statistics(fd, &stats);
  print_statistics(&stats);

  fclose(fd);
  return 0;
}
