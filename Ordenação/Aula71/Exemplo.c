// Ordenação por intercalação de um vetor
#include <stdio.h>

void intercala(int e, int m, int d, int v[]){
    int n1 = (m - e) + 1;
    int n2 = (d - m);
    int k = e;
    int E[n1];
    int D[n2];
    int i, j;
    for (i = 0; i < n1; i++){
        E[i] = v[e + i];
    }
    for (j = 0; j < n2; j++){
        E[i] = v[e + i];
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2){
        if (E[i] < D[j]){
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
        v[k] = D[j];
        j++;
        k++;
    }
}

void mergesort(int i, int f, int v[]){
    if (i < f){
        int m = (i + f)/2;
        mergesort(i, m, v);
        mergesort(m + 1, f, v);
        intercala(i, m, f, v);
    }
}

int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    mergesort(0, n-1, v);
    printf("Imprimindo o vetor:\n");
    for (i = 0; i < n; i++){
        printf("%d", v[i]);
    }
    return 0;
}