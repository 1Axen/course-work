#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);
    
    for (int _ = 0; _ < k; _++) {
        int previous = arr[n - 1];
        for (int i = 0; i < n; i++) {
            int value = arr[i];
            arr[i] = previous;
            previous = value;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}