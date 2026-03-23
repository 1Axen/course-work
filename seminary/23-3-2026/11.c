#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = 9e6;
    int min_index = -1;

    int max = -9e6;
    int max_index = -1;

    for (int i = 0; i < n; i++) {
        int value = arr[i];
        if (min > value) {
            min = value;
            min_index = i;
        }
        if (value > max) {
            max = value;
            max_index = i;
        }
    }

    printf("min: %d (%d)\n", min, min_index);
    printf("max: %d (%d)\n", max, max_index);

    return 0;
}