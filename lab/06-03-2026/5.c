#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two whole numbers: ");
    scanf("%d %d", &a, &b);

    int sum = 0;
    for (int n = a; n <= b; n++) {
        if (n % 3 == 0) {
            sum += n;
        }
    }

    printf("%d", sum);

    return 0;
}