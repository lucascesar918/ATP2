#include <stdio.h>

#define BOOKLIST_SIZE 3

typedef struct {
    char* title;
    char* author;
    int year;
} Book;

void print_booklist(Book* bl){
    for (int i=0; i<BOOKLIST_SIZE; i++)
        printf("'%s' (%d), escrito por %s.\n", bl[i].title, bl[i].year, bl[i].author);
}

int main() {
    Book books[BOOKLIST_SIZE] = {
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"The Stranger", "Albert Camus", 1942},
        {"The Burnout Society", "Byung-Chul Han", 2010}
    };

    print_booklist(books);

    return 0;
}