#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf(a == b && b == c ? "yes" : "no");

    return 0;
}