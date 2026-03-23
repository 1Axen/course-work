#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int rows = n;
    int cols = n * 2;

    int inner_cols = n / 2;
    int half_inner_cols = fmax(inner_cols / 2, 1);
    
    int inner_mid = cols / 2;
    int inner_start = inner_mid - (half_inner_cols - 1);
    int inner_end = inner_mid + half_inner_cols;

    for (int row = 1; row <= rows; row++) {
        for (int column = 1; column <= cols; column++) {
            if (column == 1 || column == inner_end) {
                if (row == 1) {
                    printf("/");
                    continue;
                }
                else if (row == rows) {
                    printf("\\");
                    continue;
                }
                else if (column != inner_end) {
                    printf("|");
                    continue;
                }
            }
            else if (column == cols || column == inner_start) {
                if (row == 1) {
                    printf("\\");
                    continue;
                }
                else if (row == rows) {
                    printf("/");
                    continue;
                }
                else if (column != inner_start) {
                    printf("|");
                    continue;
                }
            }
            else if (column >= inner_start && column <= inner_end) {
                if (row == 1 || row == rows - 1) {
                    printf("_");
                    continue;
                }
            }
            else if (row == 1) {
                printf("^");
                continue;
            }
            else if (row == rows) {
                printf("_");
                continue;
            }
            
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}