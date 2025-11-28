#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
    // Seleção aleatória do pivô
    int idx = e + (rand() % (d - e + 1));
    
    // Troca pivô aleatório com o último elemento
    int temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;

    int pivo = v[d];
    int j = e - 1;

    // Esquema de partição simples
    for (int i = e; i < d; i++) {
        if (v[i] <= pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }

    // Coloca o pivô na posição correta
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
    srand(time(NULL));  // Inicializa gerador aleatório

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
