#include <stdio.h>

int to_binary(int n) {
    if (n == 0) {
        printf("0");
    }
    
    int place = 1;
    int binary = 0;
    while (n > 0)
    {
        int bit = n % 2;
        binary += (bit * place);
        place *= 10;
        n /= 2;
    }
    
    return binary;
}

int main() {
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);
    printf("%d", to_binary(n));
    return 0;
}