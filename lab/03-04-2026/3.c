#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int k;
    scanf("%d", &k);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] == k) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < n; i++) {
            array[i] = array[i + 1];
        }

        n -= 1;
        array = (int*)realloc(array, n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}