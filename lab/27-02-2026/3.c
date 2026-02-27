#include <stdio.h>

int main() {
    int n;
    printf("Въведете цяло число: ");
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        printf("Числото е четно");
    }
    else {
        printf("Числото е нечетно");
    }

    return 0;
}