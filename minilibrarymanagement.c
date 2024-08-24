#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char author[TITLE_LENGTH];
    int year;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter book title: ");
        getchar();  // Clear buffer
        fgets(library[bookCount].title, TITLE_LENGTH, stdin);
        library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0;

        printf("Enter author: ");
        fgets(library[bookCount].author, TITLE_LENGTH, stdin);
        library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;

        printf("Enter publication year: ");
        scanf("%d", &library[bookCount].year);

        bookCount++;
        printf("Book added!\n");
    } else {
        printf("Library is full!\n");
    }
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter title to search: ");
    getchar();  // Clear buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Found: %s by %s (%d)\n", library[i].title, library[i].author, library[i].year);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. View Books\n3. Search Book\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
