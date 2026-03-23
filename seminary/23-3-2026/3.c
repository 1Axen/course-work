#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        int reverse_index = (n - i - 1);
        arr[i] = arr[reverse_index];
        arr[reverse_index] = temp;  
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}