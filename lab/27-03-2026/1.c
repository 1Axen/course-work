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

    printf("Primary diagonal: ");
    for (int row_col = 0; row_col < n; row_col++) {
        printf("%d ", matrix[row_col][row_col]);
    }
    printf("\n");

    printf("Secondary diagonal: ");
    for (int row = 0; row < n; row++) {
        int col = (n - row) - 1;
        printf("%d ", matrix[row][col]);
    }
    printf("\n");

    printf("Above primary diagonal: ");
    for (int row = 0; row < n; row++) {
        for (int col = row + 1; col < n; col++) {
            printf("%d ", matrix[row][col]);
        }
    }
    printf("\n");

    printf("Below primary diagonal: ");
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < row; col++) {
            printf("%d ", matrix[row][col]);
        }
    }

    return 0;
}