#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int seconds = a + b + c;
    int minutes = (seconds / 60);
    seconds %= 60;

    printf("%d:%02d", minutes, seconds);

    return 0;
}