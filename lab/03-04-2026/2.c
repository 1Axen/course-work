#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    char prompt;
    printf("Allocate additional elements? (y/[n]): ");
    scanf(" %c", &prompt);

    if (prompt == 'y') {
        int m;
        scanf("%d", &m);

        n += m;
        array = (int*)realloc(array, n * sizeof(int));

        for (int i = n - m; i < n; i++) {
            scanf("%d", &array[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}