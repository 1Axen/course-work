#include <stdio.h>
#include <math.h>

int main() {
    float degrees;
    printf("Enter degrees: ");
    scanf("%f", &degrees);

    float radians = degrees * (M_PI / 180.0);
    printf("%.1f° = %.2f radians", degrees, radians);
    return 0;
}