#include <stdio.h>

int main() {
    float a, b, c;
    printf("Enter the three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    if ((a + b <= c) || (a + c <= b) || (b + c) <= a) {
        printf("The numbers cannot be the sides of a triangle.");
        return 1;
    }

    if (a == b && b == c) {
        printf("Триъгълникът е равностранен.");
    }
    else if (a == b && b != c) {
        printf("Триъгълникът е равнобедрен");
    }
    else {
        printf("Триъгълникът е разностранен");
    }

    return 0;
}