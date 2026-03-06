#include <stdio.h>

int number_of_digits(int n) {
    if (n == 0) {
        return 1;
    }

    int length = 0;
    while (n > 0)
    {
        length += 1;
        n /= 10;
    }
    
    return length;
}

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);
    printf("%d цифри", number_of_digits(n));
    return 0;
}