#include <stdio.h>

int main() {
    float sum = 0;
    int numbers_entered = 0;

    while (true)
    {
        float n;
        printf("Enter a number: ");
        scanf("%f", &n);

        if (n == 0) {
            break;
        }

        sum += n;
        numbers_entered += 1;
    }
    
    printf("Брой дадени числа е %d\n", numbers_entered);
    
    if (numbers_entered > 0) {
        printf("Сумата на даденти числа е %.2f\n", sum);
        printf("Средноаритметичното им е %.2f\n", (sum / numbers_entered));
    }

    return 0;
}