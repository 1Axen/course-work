#include <stdio.h>

#define ROWS 5
#define COLS 10

int main() {
    char symbol;
    printf("Enter a symbol: ");
    scanf("%c", &symbol);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);
    printf("%c%s%c\n", symbol, "        ", symbol);
    printf("%c%s%c\n", symbol, "        ", symbol);
    printf("%c%s%c\n", symbol, "        ", symbol);
    printf("%c%c%c%c%c%c%c%c%c%c%c", symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol, symbol);

    return 0;
}