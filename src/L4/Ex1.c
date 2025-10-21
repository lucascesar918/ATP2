#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* data = "everything in its right place";
    const char* filename = "text.txt";
    FILE* fp = fopen(filename, "w");

    if (!fp) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }
    
    fputs(data, fp);
    printf("Arquivo sobrescrito com sucesso!\n");

    fclose(fp);
    return 0;
}