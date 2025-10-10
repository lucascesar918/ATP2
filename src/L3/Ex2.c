#include <stdio.h>

typedef struct {
    char* manufacturer;
    char* model;
    int year;
} Car;

void print_car(const Car* car) {
    printf("%s %s (%d)\n",
        car->manufacturer,
        car->model,
        car->year
    );
}

int main() {
    Car carro = {"Chevrolet", "Corvette C7 Stingray", 2014};
    print_car(&carro);

    return 0;
}