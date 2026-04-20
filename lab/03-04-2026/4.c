#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* n_array = (int*)malloc(n * sizeof(int));
    int* m_array = (int*)malloc(m * sizeof(int));
    
    printf("n elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &n_array[i]);
    }
    
    printf("m elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &m_array[i]);
    }

    int nm = (n + m);
    int* nm_array = (int*)(malloc(nm * sizeof(int)));
    for (int i = 0; i < nm; i++) {
        if (i >= n) {
            nm_array[i] = m_array[i - n]; 
        }
        else {
            nm_array[i] = n_array[i];
        }
    }

    qsort(nm_array, nm, sizeof(int), compare);

    for (int i = 0; i < nm; i++) {
        printf("%d ", nm_array[i]);
    }

    return 0;
}