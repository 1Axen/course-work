#include <stdio.h>

int main() {
    float inches;
    printf("Enter inches: ");
    scanf("%f", &inches);

    short option;
    printf("Choose a metric to convert to: \n");
    printf("1. mm\n"); 
    printf("2. cm\n"); 
    printf("3. dm\n");
    printf("4. m\n");
    printf("Metric index: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("%.1f Inches = %.1f mm", inches, inches * 25.4f);
        break;
    case 2:
        printf("%.1f Inches = %.2f cm", inches, inches * 2.54f);
        break;
    case 3:
        printf("%.1f Inches = %.2f dm", inches, inches * 0.254f);
        break;
    case 4:
        printf("%.1f Inches = %.2f m", inches, inches * 0.0254f);
        break;
    default:
        printf("Invalid metric selected");
        break;
    }

    return 0; 
}