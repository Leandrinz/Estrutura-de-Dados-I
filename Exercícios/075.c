#include <stdio.h>

int particao(int e, int d, int v[]) {
    int pivo = v[d];
    int j = e - 1;
    int i;

    for (i = e; i < d; i++) {
        if (v[i] <= pivo) {
            j++;
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }

    int temp = v[j + 1];
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
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    quicksort(0, n - 1, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
