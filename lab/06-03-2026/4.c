#include <stdio.h>

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);

    int temp = n;
    int reverse = 0;
    while (temp  > 0)
    {
        int digit = temp % 10;
        reverse = (reverse * 10) + digit;
        temp /= 10;
    }
    
    if (reverse == n) {
        printf("Числото е палиндром");
    }
    else {
        printf("Числтоо не е палиндром");
    }

    return 0;
}