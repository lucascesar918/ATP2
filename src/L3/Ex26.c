#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

typedef enum { Biology, Math, Physics, Chemistry, Philosophy } Subject;

typedef struct {
  char *name;
  double wage;
  Subject subject;
} Professor;

char *get_subject_name(Subject sub) {
  switch (sub) {
  case Biology:
    return "Biologia";
  case Math:
    return "Matemática";
  case Physics:
    return "Física";
  case Chemistry:
    return "Química";
  case Philosophy:
    return "Filosofia";
  default:
    return "Desconhecido";
  }
}

void print_employee(Professor *prof) {
  printf("%s ganha R$%.2f e dá aula de %s.\n", prof->name, prof->wage,
         get_subject_name(prof->subject));
}

int main() {
  Professor emp = {"Alice", 15000.0, Biology};
  Professor emp2 = {"Bárbara", 12000.0, Math};
  Professor emp3 = {"Carlos", 8000.0, Physics};
  Professor emp4 = {"Daniel", 5000.0, Chemistry};
  Professor emp5 = {"Eduardo", 3000.0, Philosophy};

  print_employee(&emp);
  print_employee(&emp2);
  print_employee(&emp3);
  print_employee(&emp4);
  print_employee(&emp5);

  return 0;
}