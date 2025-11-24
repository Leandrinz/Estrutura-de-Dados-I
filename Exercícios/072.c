#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int posicao;
    char nome[100];
} Piloto;

void intercala(Piloto v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int tamanho = fim - inicio + 1;
    Piloto *temp = (Piloto*)malloc(tamanho * sizeof(Piloto));

    while (i <= meio && j <= fim) {
        if (v[i].posicao <= v[j].posicao)
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= meio)
        temp[k++] = v[i++];
    while (j <= fim)
        temp[k++] = v[j++];

    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = temp[k];

    free(temp);
}

void mergeSort(Piloto v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        intercala(v, inicio, meio, fim);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Piloto pilotos[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &pilotos[i].posicao, pilotos[i].nome);
    }

    mergeSort(pilotos, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", pilotos[i].posicao, pilotos[i].nome);
    }

    return 0;
}
