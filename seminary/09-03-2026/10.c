#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int n_le_200 = 0;
    int n_le_400 = 0;
    int n_le_600 = 0;
    int n_le_800 = 0;
    int n_remainder = 0;

    for (int _ = 0; _ < n; _++) {
        int number;
        scanf("%d", &number);

        if (number < 200) {
            n_le_200 += 1;
        }
        else if (number < 400) {
            n_le_400 += 1;
        }
        else if (number < 600) {
            n_le_600 += 1;
        }
        else if (number < 800) {
            n_le_800 += 1;
        }
        else {
            n_remainder += 1;
        }
    }

    int p1 = ((float)n_le_200 / (float)n) * 100.0f;
    int p2 = ((float)n_le_400 / (float)n) * 100.0f;
    int p3 = ((float)n_le_600 / (float)n) * 100.0f;
    int p4 = ((float)n_le_800 / (float)n) * 100.0f;
    int p5 = ((float)n_remainder / (float)n) * 100.0f;

    printf("p1: %d\\%\n", p1);
    printf("p2: %d\\%\n", p2);
    printf("p3: %d\\%\n", p3);
    printf("p4: %d\\%\n", p4);
    printf("p5: %d\\%\n", p5);

    return 0;
}