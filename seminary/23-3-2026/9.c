#include <stdio.h>

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

    for (int i = longest_index; i < longest_index + longest_length; i++) {
        printf("%d ", arr[i], i);
    }

    return 0;
}