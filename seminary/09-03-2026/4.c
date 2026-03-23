#include <stdio.h>

int main() {
    int points;
    scanf("%d", &points);

    float bonus = 0.0f;
    if (points <= 100) {
        bonus = 5.0f;
    }
    else if (points <= 1000) {
        bonus = (points * 0.20f);
    }
    else {
        bonus = (points * 0.10f);
    }

    if (points % 2 == 0) {
        bonus += 1.0f;
    }

    if (points % 10 == 5) {
        bonus += 2.0f;
    }

    printf("%g\n%g", bonus, points + bonus);

    return 0;
}