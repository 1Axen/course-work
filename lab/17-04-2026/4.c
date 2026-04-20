#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int year;
    double price;
} Book;

void analyze_books(Book books[], int n) {
    int minIdx = 0;
    int maxIdx = 0;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        if (books[i].price < books[minIdx].price) {
            minIdx = i;
        }
        if (books[i].price > books[maxIdx].price) {
            maxIdx = i;
        }
        sum += books[i].price;
    }

    printf("Cheapest book:\n");
    printf("  Title: %s\n", books[minIdx].title);
    printf("  Author: %s\n", books[minIdx].author);
    printf("  Year: %d\n", books[minIdx].year);
    printf("  Price: %.2f\n", books[minIdx].price);

    printf("\nMost expensive book:\n");
    printf("  Title: %s\n", books[maxIdx].title);
    printf("  Author: %s\n", books[maxIdx].author);
    printf("  Year: %d\n", books[maxIdx].year);
    printf("  Price: %.2f\n", books[maxIdx].price);

    printf("\nAverage price: %.2f\n", sum / n);
}

int main() {
    Book books[5];

    strcpy(books[0].title, "Under the Yoke");
    strcpy(books[0].author, "Ivan Vazov");
    books[0].year = 1894;
    books[0].price = 15.50;

    strcpy(books[1].title, "Tobacco");
    strcpy(books[1].author, "Dimitar Dimov");
    books[1].year = 1951;
    books[1].price = 22.00;

    strcpy(books[2].title, "Time of Parting");
    strcpy(books[2].author, "Anton Donchev");
    books[2].year = 1964;
    books[2].price = 18.75;

    strcpy(books[3].title, "Bai Ganyo");
    strcpy(books[3].author, "Aleko Konstantinov");
    books[3].year = 1895;
    books[3].price = 10.00;

    strcpy(books[4].title, "The Iron Candlestick");
    strcpy(books[4].author, "Dimitar Talev");
    books[4].year = 1952;
    books[4].price = 25.90;

    analyze_books(books, 5);

    return 0;
}