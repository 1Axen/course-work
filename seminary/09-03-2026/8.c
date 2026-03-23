#include <stdio.h>

int main() {
    float volume;
    float pipe1_liters, pipe2_liters;
    int time_hours;

    scanf("%f %f %f %d", &volume, &pipe1_liters, &pipe2_liters, &time_hours);

    float capacity_liters = volume * 1000.0f;
    float water_poured_liters = (pipe1_liters * time_hours) 
        + (pipe2_liters * time_hours);

    if (water_poured_liters == capacity_liters) {
        printf("The pool is filled.");
    }
    else if (water_poured_liters > capacity_liters) {
        printf("The pool has overflowed.");
    }
    else {
        int percentage = (water_poured_liters / capacity_liters) * 100.0f;
        printf("The pool is %d percent filled.", percentage);
    }

    return 0;
}