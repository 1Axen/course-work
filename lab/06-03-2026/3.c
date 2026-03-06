#include <stdio.h>

int main() {
    int n;
    printf("Enter a whole number (1-12): ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("Януари (Зима)");
        break;
    case 2:
        printf("Февруари (Зима)");
        break;
    case 3:
        printf("Март (Пролет)");
        break;
    case 4:
        printf("Април (Пролет)");
        break;
    case 5:
        printf("Май (Пролет)");
        break;
    case 6:
        printf("Юни (Лято)");
        break;
    case 7:
        printf("Юли (Лято)");
        break;
    case 8:
        printf("Август (Лято)");
        break;
    case 9:
        printf("Септември (Есен)");
        break;
    case 10:
        printf("Октомври (Есен)");
        break;
    case 11:
        printf("Ноември (Есен)");
        break;
    case 12:
        printf("Януари (Зима)");
        break;
    default:
        printf("The number %d is invalid", n);
        break;
    }

    return 0;
}