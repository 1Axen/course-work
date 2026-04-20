#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    int smallest_row = -1;
    int smallest_value = 1 << 30;

    int largest_row = -1;
    int largest_value = 1 << 31;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int value = matrix[row][col];
            if (value < smallest_value) {
                smallest_row = row;
                smallest_value = value;
            }
            if (value > largest_value) {
                largest_row = row;
                largest_value = value;
            }
        }
    }

    if (smallest_row == -1 || largest_row == -1 || smallest_row == largest_row) {
        return 1;
    }

    for (int col = 0; col < m; col++) {
        int t = matrix[smallest_row][col];
        matrix[smallest_row][col] = matrix[largest_row][col];
        matrix[largest_row][col] = t;
    }

    printf("Matrix:\n");

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}