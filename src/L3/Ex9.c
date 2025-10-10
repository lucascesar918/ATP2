#include <stdio.h>

typedef struct {
    char* name;
    int age;
    float height;
} Person;

int main() {
    Person pessoa = {"Carla", 18, 1.78};

    printf("Struct de tamanho %lu bytes\n", sizeof(pessoa));

    return 0;
}