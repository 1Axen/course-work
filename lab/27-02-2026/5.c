#include <stdio.h>

int main() {
    int year;
    printf("Въведете година: ");
    scanf("%d", &year);

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        printf("Годината е високосна");
    }
    else {
        printf("Годината не е високосна");
    }

    return 0;
}