#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("Въведете 3 цели числа: ");
    scanf("%d %d %d", &a, &b, &c);

    int max_n = fmax(fmax(a, b), c);
    printf("Най-голямото число: %d", max_n);

    return 0;
}