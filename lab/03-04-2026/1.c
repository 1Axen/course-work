#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* n_array = (int*)malloc(n * sizeof(int));
    int* m_array = (int*)malloc(m * sizeof(int));
    
    printf("n elements: ");
    int n_sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &n_array[i]);
        n_sum += n_array[i];
    }
    
    printf("m elements: ");
    int m_sum = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &m_array[i]);
        m_sum += m_array[i];
    }

    int sum = (n_sum + m_sum);
    float average = (float)sum / (float)(n + m);
    printf("sum: %d\naverage: %g", sum, average);

    return 0;
}