#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    int rotated[n][n];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            rotated[col][n - 1 - row] = matrix[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", rotated[row][col]);
        }
        printf("\n");
    }

    return 0;
}