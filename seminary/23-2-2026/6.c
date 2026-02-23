#include <stdio.h>

int main() {
    float a, b, h;
    printf("Enter a in cm: ");
    scanf("%f", &a);

    printf("Enter b in cm: ");
    scanf("%f", &b);

    printf("Enter h in cm: ");
    scanf("%f", &h);

    float trapezoid_area = ((a + b) / 2) * h;
    printf("The trapezoid area is %.1f cm2", trapezoid_area);
    
    return 0;
}