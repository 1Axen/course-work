#include <stdio.h>

int main() {
    int degrees_celcius;
    printf("Enter degrees in celcius: ");
    scanf("%d", &degrees_celcius);

    float degrees_fahrenheit = (degrees_celcius * (9.0f/5.0f)) + 32;
    printf("%d° celcius = %.1f° fahrenheit", degrees_celcius, degrees_fahrenheit);
    return 0;
}