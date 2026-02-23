#include <stdio.h>
#include <math.h>

int main() {
    float a_x, a_y;
    float b_x, b_y;

    printf("Enter point A (x, y): ");
    scanf_s("%f %f", &a_x, &a_y);

    printf("Enter point B (x, y): ");
    scanf_s("%f %f", &b_x, &b_y);

    float width = fabsf(a_x - b_x);
    float height = fabsf(a_y - b_y);
    float area = width * height;
    printf("The area of the triangle is %.2f cm2", area);

    return 0;
}