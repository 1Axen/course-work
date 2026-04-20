#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_ITEMS 4

int capacities[N_ITEMS] = {1, 8, 6, 6};
float prices[N_ITEMS] = {13.99, 42.0, 5.98, 21.02};
const char* names[N_ITEMS] = {"Chair", "Table", "Cups", "Dishes"};

int main() {
    int n_guests;
    scanf("%d", &n_guests);

    int counts[N_ITEMS] = {0, 0, 0, 0};
    float total_spent = 0;

    while (true)
    {
        char input[8];
        scanf("%7s", &input);

        if (strcmp(input, "PARTY!") == 0) {
            break;
        }

        int index = -1;
        for (int i = 0; i < N_ITEMS; i++) {
            const char* name = names[i];
            if (strcmp(input, name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Unknown item \"%s\"", input);
            continue;
        }

        counts[index]++;
        total_spent += prices[index];
    }

    printf("%g", total_spent);
    for (int i = 0; i < N_ITEMS; i++) {
        int count = counts[i];
        int capacity = capacities[i];
        int available_capacity = count * capacity;
        if (available_capacity >= n_guests) {
            continue;
        }

        int needed_capacity = n_guests - available_capacity;
        int n_more_to_buy = ceil((float)needed_capacity / (float)capacity);
        printf("\n%d %s", n_more_to_buy, names[i]);
    }

    return 0;
}