#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bool relation_upheld = true;
    for (int i = 1; i < n; i++) {
        int prev = arr[i - 1];
        int value = arr[i];

        if (i % 2 == 0) {
            if (value > prev) {
                relation_upheld = false;
                break;
            }
        }
        else if (value < prev) {
            relation_upheld = false;
            break;
        }
    }

    if (relation_upheld == false) {
        printf("The relation is not upheld");
    }
    else {
        printf("The relation is upheld");
    }

    return 0;
}