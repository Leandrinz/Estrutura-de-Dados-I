// Ordenação por intercalação de estruturas
#include <stdio.h>

typedef struct
{
    int mat;
    char nome[50];
}estudante;


void intercala(int e, int m, int d, estudante v[]){
    int n1 = (m - e) + 1;
    int n2 = d - m;
    int k = e;
    estudante E[n1];
    estudante D[n2];
    int i, j;
    for (i = 0; i < n1; i++){
        E[i] = v[e + i];
    }
    for (j = 0; j < n2; j++){
        D[j] = v[m + 1 + j];
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2){
        if (E[i].mat < D[j].mat){
            v[k] = E[i];
            i++;
        }
        else{
            v[k] = D[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        v[k] = E[i];
        i++;
        k++;
    }
    while (j < n2){
        v[k] = E[j];
        j++;
        k++;
    }
}

void mergeSort (int i, int f, estudante v[]){
    if (i < f){
        int m = (i + f) / 2;
        mergeSort(i, m, v);
        mergeSort(m + 1, f, v);
        intercala(i, m, f, v);
    }
}

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    mergeSort(0, n - 1, v);
    printf("Imprimindo o vetor:\n");
    for (i = 0; i < n; i++){
        printf("%s:%d", v[i].nome, v[i].mat);
    }
    printf("\n");
    return 0;
}