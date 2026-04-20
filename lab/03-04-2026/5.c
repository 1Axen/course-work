#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int** triangle = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("  Ред %2d: ", i);
        for (int j = 0; j <= i; j++) {
            printf("%d", triangle[i][j]);
            if (j < i) printf(", ");
        }
        printf("\n");
    }

    return 0;
}