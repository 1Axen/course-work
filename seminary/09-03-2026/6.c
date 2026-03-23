#include <stdio.h>

int main() {
    float x, y;
    scanf("%f %f", &x, &y);
    // x1, y2
    float min_x, min_y;
    scanf("%f %f", &min_x, &min_y);
    // x2, y2
    float max_x, max_y;
    scanf("%f %f", &max_x, &max_y);

    if (x < min_x || x > max_x || y < min_y || y > max_y ) {
        printf("Outside");
        return 1;
    }

    printf("Inside");

    return 0;
}