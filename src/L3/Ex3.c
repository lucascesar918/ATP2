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
    Car novo_carro = {"Chevrolet", "Corvette C5 Z06", 2001};

    novo_carro.manufacturer = carro.manufacturer;
    novo_carro.model = carro.model;
    novo_carro.year = carro.year;

    print_car(&novo_carro);

    return 0;
}