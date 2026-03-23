#include <stdio.h>

#define USEABLE_AREA 0.4f
#define KG_PER_LITER 2.5f

int main() {
    float area;
    float grapes_yield;
    float liters_wine_required;

    scanf("%f %f %f", &area, &grapes_yield, &liters_wine_required);

    area *= USEABLE_AREA;
    float kg_grapes = area * grapes_yield;
    float liters_wine = kg_grapes / KG_PER_LITER;

    printf("Liters wine produced: %g\n", liters_wine);

    if (liters_wine < liters_wine_required) {
        printf("The wine produced does not meet the requirement.");
    }
    else {
        float remainder_liters = (liters_wine - liters_wine_required);
        printf("The wine produced meets the requirement.\n");
        printf("The remaining %g liters of wine can be given to the workers.", remainder_liters);
    }

    return 0;
}