#include <stdio.h>
#include <math.h>

int main() {
    float a_x, a_y;
    float b_x, b_y;
    float c_x, c_y;

    printf("Enter point A (x, y): ");
    scanf_s("%f %f", &a_x, &a_y);

    printf("Enter point B (x, y): ");
    scanf_s("%f %f", &b_x, &b_y);

    printf("Enter point C (x, y): ");
    scanf_s("%f %f", &c_x, &c_y);

    float area = 0.5 * (a_x * (b_y - c_y) + b_x * (c_y - a_y) + c_x * (a_y - b_y));
    printf("The area of the triangle is %.2f cm2", area);

    return 0;
}