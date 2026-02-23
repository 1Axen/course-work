#include <stdio.h>

int main() {
    float bgn;
    printf("Enter BGN: ");
    scanf("%f", &bgn);

    short option;
    printf("Choose a currency to convert to: \n");
    printf("1. EUR\n"); 
    printf("2. USD\n"); 
    printf("3. GBP\n");
    printf("Currency index: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("%.2f BGN = %.1f EUR", bgn, bgn * 0.511f);
        break;
    case 2:
        printf("%.2f BGN = %.2f USD", bgn, bgn * 0.603f);
        break;
    case 3:
        printf("%.2f BGN = %.2f GBP", bgn, bgn * 0.446f);
        break;
    default:
        printf("Invalid currency selected");
        break;
    }

    return 0; 
}