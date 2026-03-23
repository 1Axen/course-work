#include <stdio.h>

#define TAXI_BASE 0.7f
#define TAXI_DAY 0.79f
#define TAXI_NIGHT 0.90f

#define BUS_PRICE 0.09f
#define BUS_MINIMUM_KM 20

#define TRAIN_PRICE 0.06f
#define TRAIN_MINIMUM_KM 100

int main() {
    float n;
    char period;
    scanf("%f %c", &n, &period);

    if (n < BUS_MINIMUM_KM) {
        float price_per_km = period == "D" ? TAXI_DAY : TAXI_NIGHT;
        printf("Taxi price: %g BGN", TAXI_BASE + (price_per_km * n));
    }
    else if (n < TRAIN_MINIMUM_KM) {
        printf("Bus price: %g BGN", n * BUS_PRICE);
    }
    else {
        printf("Train price: %g BGN", n * TRAIN_PRICE);
    }

    return 0;
}