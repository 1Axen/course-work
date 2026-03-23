#include <stdio.h>

int main() {
    int hour, minutes;
    scanf("%d", &hour);
    scanf("%d", &minutes);

    int seconds = (hour * 3600) + (minutes * 60);
    seconds += (15 * 60);
    seconds %= 3600 * 24;

    hour = seconds / 3600;
    seconds %= 3600;
    minutes = seconds / 60;

    printf("%d:%02d", hour, minutes);

    return 0;
}