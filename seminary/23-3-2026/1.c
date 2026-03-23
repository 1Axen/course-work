#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(&arr, n, sizeof(int), compare);

    int longest_index = 0;
    int longest_length = 1;

    int current_index = 0;
    int current_length = 1;
    int current_value = arr[0];
    
    for (int i = 1; i < n; i++) {
        int value = arr[i]; 
        if (value == current_value) {
            current_length += 1;

            if (current_length > longest_length) {
                longest_index = current_index;
                longest_length = current_length;
            }

            continue; 
        }
        else {
            current_index = i;
            current_length = 1;
            current_value = value; 
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nIndex: %d, Length: %d, Value: %d", longest_index, longest_length, arr[longest_index]);

    return 0;
}