#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Argumentos insuficientes!\n\nUso: %s <arquivo fonte>", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    if (!fp) {
        perror("Falha ao abrir o arquivo.");
        return 1;
    }

    char ch;
    int count = 1;

    while ((ch = fgetc(fp)) && ch != EOF)
        if (ch == '\n')
            count++;

    printf("O arquivo %s tem %d linhas.\n", argv[1], count);

    fclose(fp);

    return 0;
}