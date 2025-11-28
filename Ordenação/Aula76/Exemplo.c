// Quicksort - pivô aleatório
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
    int idx = e + (rand() % (d - e + 1));  // pivô aleatório entre e e d

    int temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;

    int pivo = v[d];
    int j = e - 1;

    for (int i = e; i < d; i++) {
        if (v[i] < pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }

    temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;

    return j + 1;
}

void quicksort(int e, int d, int v[]) {
    if (e < d) {
        int p = particao(e, d, v);
        quicksort(e, p - 1, v);
        quicksort(p + 1, d, v);
    }
}

int main() {
    srand(time(NULL));  // seed do rand deve ser chamada UMA vez só

    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    quicksort(0, n - 1, v);

    printf("Imprimindo o vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
