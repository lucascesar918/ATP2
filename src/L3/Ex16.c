#include <stdio.h>

typedef struct {
  char *title;
  char *director;
  int year;
} Movie;

void print_movie_copy(Movie movie) {
  printf("'%s' (%d), dirigido por %s.\n", movie.title, movie.year,
         movie.director);
}

int main() {
  Movie movie = {"O Estranho Mundo de Jack", "Henry Selick", 1993};

  print_movie_copy(movie);
  return 0;
}