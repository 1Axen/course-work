#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int reverse[n];
    for (int i = 0; i < n; i++) {
        reverse[n - i - 1] = arr[i];  
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", reverse[i]);
    }

    return 0;
}