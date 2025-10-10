#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLASSROOM_CAPACITY 5
#define BUFSIZE 100

typedef struct
{
    char *name;
    char *registration;
    float gpa;
} Student;

typedef struct
{
    char *name;
    int enrolled;
    int capacity;
    Student *students;
} Classroom;

typedef enum
{
    MENU,
    ADD,
    REMOVE,
    LIST,
    EXIT
} View;

void clear_stdin() {
    while(getchar() != '\n');
}

void strip_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void wait_enter(){
    printf("Aperte [ENTER] para continuar.");
    clear_stdin();
    getchar();
}

int add_student(Classroom *classroom, Student student)
{
    if (classroom->enrolled >= classroom->capacity)
        return 1;

    classroom->students[classroom->enrolled++] = student;
    return 0;
}

int remove_student(Classroom *classroom)
{
    if (classroom->enrolled <= 0)
        return 1;

    free(classroom->students[classroom->enrolled - 1].name);
    free(classroom->students[classroom->enrolled - 1].registration);

    classroom->enrolled--;
    return 0;
}

void print_students(const Classroom *classroom)
{
    if (classroom->enrolled == 0)
    {
        printf("Nenhum aluno matriculado.\n");
        return;
    }

    for (int i = 0; i < classroom->enrolled; i++)
    {
        Student s = classroom->students[i];
        printf("%s, Matrícula: %s, GPA: %.2f\n", s.name, s.registration, s.gpa);
    }
}

void ui_menu(Classroom* classroom)
{
    printf("Gerenciando '%s'\n", classroom->name);
    printf("1. Adicionar aluno\n");
    printf("2. Remover aluno\n");
    printf("3. Listar alunos\n");
    printf("4. Sair\n");
}

void ui_add(Classroom* classroom)
{
    if (classroom->enrolled >= classroom->capacity) {
        printf("A sala está cheia. Não é possível adicionar mais alunos.\n");
        return;
    }

    char *name = malloc(BUFSIZE * sizeof(char));
    char *registration = malloc(BUFSIZE * sizeof(char));
    char fbuf[BUFSIZE];
    float gpa;
    Student student;

    clear_stdin();
    printf("Digite o nome do aluno: ");
    fgets(name, BUFSIZE, stdin);
    strip_newline(name);

    printf("Digite a matrícula do aluno: ");
    fgets(registration, BUFSIZE, stdin);
    strip_newline(registration);

    printf("Digite o GPA do aluno: ");
    fgets(fbuf, BUFSIZE, stdin);
    gpa = strtof(fbuf, NULL);
    student.name = name;
    student.registration = registration;
    student.gpa = gpa;

    if (add_student(classroom, student) == 0)
        printf("Aluno adicionado com sucesso!\n");
    else
        printf("Erro ao adicionar aluno.\n");

    wait_enter();
}

void ui_remove(Classroom* classroom)
{
    if (classroom->enrolled <= 0) {
        printf("Nenhum aluno para remover.\n");
        return;
    }

    Student s = classroom->students[classroom->enrolled - 1];
    printf("Removendo aluno: %s, Matrícula: %s, GPA: %.2f\n", s.name, s.registration, s.gpa);
    printf("Tem certeza que deseja remover este aluno? (s/N): ");
    clear_stdin();
    char response = getchar();
    if (response != 'S' && response != 's') {
        printf("Remoção cancelada.\n");
        return;
    }
    remove_student(classroom);
    printf("Aluno removido com sucesso!\n");

    wait_enter();
}

void ui_list(Classroom* classroom)
{
    printf("Listando alunos...\n");
    if (classroom->enrolled <= 0) {
        printf("Nenhum aluno matriculado.\n");
        return;
    }

    print_students(classroom);
}

View get_choice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void handle_choice(Classroom* classroom)
{
    printf("\nEscolha uma opção: ");
    switch (get_choice())
    {
    case MENU:
        ui_menu(classroom);
        break;
    case ADD:
        ui_add(classroom);
        break;
    case REMOVE:
        ui_remove(classroom);
        break;
    case LIST:
        ui_list(classroom);
        break;
    case EXIT:
        printf("Saindo...\n");
        exit(0);
    default:
        printf("Opção inválida. Escolha uma opção informada abaixo.\n");
        break;
    }
    printf("\n");
}

void free_classroom(Classroom* classroom) {
    for (int i=0; i<classroom->enrolled; i++) {
        free(classroom->students[i].name);
        free(classroom->students[i].registration);
    }
    free(classroom->students);
    free(classroom->name);
    free(classroom);
}

int main()
{
    Classroom sala = {"Sala 1", 0, CLASSROOM_CAPACITY, malloc(CLASSROOM_CAPACITY * sizeof(Student))};
    Student student;

    while (1)
    {
        ui_menu(&sala);
        handle_choice(&sala);
    }

    free_classroom(&sala);
    return 0;
}