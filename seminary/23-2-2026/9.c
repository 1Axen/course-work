#include <stdio.h>
#include <math.h>

#define DESK_WIDTH 1.2f
#define DESK_HEIGHT 0.7f
#define HALLWAY_WIDTH 1.0f

int main() {
    float width, height;
    
    printf("Enter the width in meters: ");
    scanf("%f", &width);

    printf("Enter the height in meters: ");
    scanf("%f", &height);

    float available_width = width - HALLWAY_WIDTH;
    int desks_by_width = floorf(available_width / DESK_WIDTH);
    int desks_by_height = floorf(height / DESK_HEIGHT);

    int desks = (desks_by_width * desks_by_height);
    desks = desks <= 3 ? 0 : desks - 3;

    printf("The numbers of desks is %d", desks);
    return 0;
}