#include <stdio.h>

int main() {
    int n;
    printf("Въведете цяло число: ");
    scanf("%d", &n);

    do
    {
        int digit = n % 10;
        printf("%d ", digit);

        n /= 10;
    } while (n != 0);
    
    return 0;
}