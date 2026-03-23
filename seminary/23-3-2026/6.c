#include <stdio.h>

int sign(int x, int y) {
    return x > y ? -1 : 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int longest_index = 0;
    int longest_length = 1;

    int current_index = 0;
    int current_length = 1;
    int current_direction = sign(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int direction = sign(arr[i - 1], arr[i]);
        if (direction == current_direction) {
            current_length += 1;
            if (current_length > longest_length) {
                longest_index = current_index;
                longest_length = current_length;
            }

            continue;
        }

        current_index = i - 1;
        current_length = 1;
        current_direction = direction;
    }

    for (int i = longest_index; i <= longest_index + longest_length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}