#include <stdio.h>

#define NO_VALUE 1 << 31

int main() {
    int n;
    scanf("%d", &n);

    int square[n][n];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            scanf("%d", &square[row][col]);
        }
    }

    int magic_sum = NO_VALUE;
    bool is_magical = true;
    for (int row = 0; row < n; row++) {
        int col_sum = 0;
        int row_sum = 0;

        for (int col = 0; col < n; col++) {
            row_sum += square[row][col];
            col_sum += square[col][row];
        }

        if (magic_sum == NO_VALUE) {
            magic_sum = row_sum;
        }

        if (col_sum != magic_sum || row_sum != magic_sum) {
            is_magical = false;
            break;
        }
    }

    if (is_magical) {
        printf("The square is magical");
    }
    else {
        printf("The square is not magical");
    }

    return 0;
}