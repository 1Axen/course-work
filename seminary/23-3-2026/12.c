#include <stdio.h>

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int arr[n];
    arr[0] = k;

    for (int i = 1; i < n; i++) {
        arr[i] = (i + 1) * k;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}