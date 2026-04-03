#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            int directed_col = (row % 2 == 0) ? col : (n - col) - 1;
            matrix[row][directed_col] = row * n + col + 1;
        }
    }

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}