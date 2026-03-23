#include <stdio.h>
#include <math.h>

float max(float a, float b) {
    return a < b ? b : a;
}

float min(float a, float b) {
    return a < b ? a : b;
}

int main() {
    float min_number = INFINITY;
    float max_number = -INFINITY;

    while (true)
    {
        float n;
        printf("Enter a number: ");
        scanf("%f", &n);
        
        if (n == 0) {
            break;
        }

        min_number = min(min_number, n);
        max_number = max(max_number, n);
    }

    printf("The minimum number was: %.2f\n", min_number);
    printf("The maximum number was: %.2f\n", max_number);

    return 0;
}