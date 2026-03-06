#include <stdio.h>

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("The number is even\n");
    }
    else {
        printf("The number is odd\n");
    }

    if (n == 0)
    {
        printf("The number is 0\n");   
    }
    else if (n < 0)
    {
        printf("The number is negative\n");
    }
    else {
        printf("The number is positive\n");
    }
    
    if ((n % 3 + n % 5) == 0) {
        printf("The number is divisable by 3 and 5\n");
    }

    return 0;
}