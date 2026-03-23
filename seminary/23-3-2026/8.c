#include <stdio.h>
#include <mem.h>

int main() {
    int arr[20];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int size = 10;
    while (size < 20) 
    {
        int n, index;
        scanf("%d %d", &n, &index);

        if (n == 0) {
            break;
        }

        memmove(&arr[index + 1], &arr[index], (size-index) * sizeof(int));
        arr[index] = n;
        size += 1;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}