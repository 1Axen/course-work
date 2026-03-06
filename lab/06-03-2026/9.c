#include <stdio.h>
#include <math.h>

int NOD(int a, int b) {
    int result = 1;
    int max_i = fmin(a, b);
    for (int i = 1; i <= max_i; i++) {
        if (a % i == 0 && b % i == 0) {
            result = i;
        }
    }

    return result;
}

int main() {
    int a, b;
    printf("Enter two whole numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("НОД(%d, %d) = %d", a, b, NOD(a, b));

    return 0;
}