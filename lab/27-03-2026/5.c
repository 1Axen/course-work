#include <stdio.h>

int main() {
    printf("Matrix A: \n");
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n];
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            scanf("%d", &A[row][col]);
        }
    }

    printf("\nMatrix B: \n");
    int p, q;
    scanf("%d %d", &p, &q);

    int B[m][n];
    for (int row = 0; row < p; row++) {
        for (int col = 0; col < q; col++) {
            scanf("%d", &B[row][col]);
        }
    }

    int at_row = -1, at_col = -1;
    for (int row = 0; row <= m - p; row++) {
        for (int col = 0; col <= n - q; col++) {
            int found = true;
            for (int k = 0; k < p && found; k++)
                for (int l = 0; l < q; l++)
                    if (A[row + k][col + l] != B[k][l])
                        found = false;
                        break;
            
            if (found) {
                at_row = row;
                at_col = col;
                goto after_search;
            }
        }
    }

after_search:
    if (at_row != -1) {
        printf("The matrix B is contained in A, from row %d, col %d.", at_row, at_col);
    }
    else {
        printf("The matrix B is not contained in A.");
    }

    return 0;
}