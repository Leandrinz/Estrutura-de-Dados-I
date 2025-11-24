#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int nivel_ameaca;
} Nave;

// Função para intercalar duas metades
void merge(Nave v[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = 0;
    int tamanho = fim - inicio + 1;

    Nave *temp = (Nave*)malloc(tamanho * sizeof(Nave));

    while (i <= meio && j <= fim) {
        if (v[i].nivel_ameaca <= v[j].nivel_ameaca) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }
    while (i <= meio) temp[k++] = v[i++];
    while (j <= fim) temp[k++] = v[j++];

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
    }

    free(temp);
}

// Merge Sort recursivo
void mergeSort(Nave v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Nave naves[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &naves[i].id, &naves[i].nivel_ameaca);
    }

    mergeSort(naves, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", naves[i].id);
    }

    return 0;
}
