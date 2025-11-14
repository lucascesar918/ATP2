#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_COURSE 30

typedef struct {
  int id;
  char name[MAX_NAME];
  char course[MAX_COURSE];
  float grade;
} Student;

void print_student(Student *student) {
  printf("\nID: %d\n", student->id);
  printf("Nome: %s\n", student->name);
  printf("Curso: %s\n", student->course);
  printf("Nota: %.2f\n", student->grade);
  printf("----------------------------------------\n");
}

size_t get_file_size(FILE *fd) {
  long current_pos = ftell(fd);
  fseek(fd, 0, SEEK_END);
  size_t fsize = (size_t)ftell(fd);
  fseek(fd, current_pos, SEEK_SET);
  return fsize;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Argumentos inválidos!\n\nUso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  FILE *fd = fopen(argv[1], "rb");
  if (!fd) {
    fprintf(stderr, "Erro ao abrir o arquivo '%s'\n", argv[1]);
    return 1;
  }

  size_t total_students = get_file_size(fd) / sizeof(Student);
  if (total_students == 0) {
    fprintf(stderr, "O arquivo está vazio ou não contém registros válidos\n");
    fclose(fd);
    return 1;
  }

  printf("Total de alunos encontrados: %zu\n", total_students);
  printf("========================================\n");

  Student student;
  while (fread(&student, sizeof(Student), 1, fd) == 1)
    print_student(&student);

  fclose(fd);
  return 0;
}
