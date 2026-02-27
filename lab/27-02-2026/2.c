#include <stdio.h>

int main() {
    float a, b;
    printf("Въведете две числа: ");
    scanf("%f %f", &a, &b);
    printf("Сума: %.2f\n", a + b);
    printf("Разлика: %.2f\n", a - b);
    printf("Произведение: %.2f\n", a * b);
    printf("Частно: %.2f\n", a / b);
    return 0;
}