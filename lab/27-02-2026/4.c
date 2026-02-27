#include <stdio.h>

int main() {
    int n;
    printf("Въведете 4 цифрено число: ");
    scanf("%d", &n);

    int sum = n % 10; n /= 10;
    sum += n % 10; n /= 10;
    sum += n % 10; n /= 10;
    sum += n % 10;

    printf("Сумата на цифрите е: %d", sum);

    return 0;
}