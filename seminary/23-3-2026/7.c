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

    int start_index = -1;
    int end_index = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                start_index = i;
                end_index = j;
                goto found_index;
            }
            else if (sum > k) {
                break;
            }
        }
    }

    if (start_index != 1) {
    found_index:
        for (int i = start_index; i <= end_index; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}