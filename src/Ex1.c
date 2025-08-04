#include <stdio.h>
#include <stdlib.h>

void populate_array(int* array, size_t size);
void print_array(int* array, size_t size);

int main(int argc, char** argv) {
    const size_t arrlen = 10;
    int* array = malloc(arrlen*sizeof(int));

    // Checando falha de alocação de memória
    if (array == NULL) {
        perror("Falha ao alocar memória para o array!\n");
        return EXIT_FAILURE;
    }

    populate_array(array, arrlen);
    print_array(array, arrlen);

    free(array);
    return EXIT_SUCCESS;
}

// Função para preencher o array
void populate_array(int* array, size_t size) {
    for (size_t j=0; j<size; j++)
        array[j] = j;
}

// Função para printar os valores do array
void print_array(int* array, size_t size) {
    for (size_t c=0; c<size; c++)
        printf("[%2.zu°]: %d\n", c+1, array[c]);
}
