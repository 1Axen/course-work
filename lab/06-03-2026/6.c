#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);

    int max = 0;
    while (n > 0)
    {
        int digit = (n % 10);
        max = fmax(max, digit);
        n /= 10;
    }

    printf("Най-голямата цифра е %d.", max);

    return 0;
}