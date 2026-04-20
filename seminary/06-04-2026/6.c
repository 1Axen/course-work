#include <stdio.h>
#include <stdlib.h>

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    } 

    if (x % x != 0) {
        return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        } 
    }

    return true;
}

void print_array(char* label, int* array, int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int* primes = NULL;
    int n_primes = 0;

    for (int i = n - 1; i >= 0; i--) {
        int value = array[i];
        if (!is_prime(value)) {
            continue;
        }
 
        // grow
        n_primes += 1;
        primes = realloc(primes, n_primes * sizeof(int));
        primes[n_primes - 1] = value;

        // shrink
        for (int j = i + 1; j < n; j++) {
            array[j - 1] = array[j];
        }

        n -= 1;
        array = realloc(array, n * sizeof(int));
    }

    print_array("array", array, n);
    print_array("primes", primes, n_primes);

    return 0;
}