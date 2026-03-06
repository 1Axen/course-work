#include <stdio.h>

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);

    int a = 1, b = 1;
    while (a <= n)
    {
        printf("%d ", a);
        int next = (a + b);
        a = b;
        b = next;
    }

    return 0;
}