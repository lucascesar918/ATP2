#include <stdio.h>

typedef struct {
    char* name;
    char* registration;
    double grade;
} Student;

void print_student(const Student* student) {
    printf("[%s] %s: %.2f\n",
        student->registration,
        student->name,
        student->grade
    );
}

int main() {
    Student aluno = {"Felipe Olavo Hino Barbosa", "251254331", 9.2};

    print_student(&aluno);

    return 0;
}