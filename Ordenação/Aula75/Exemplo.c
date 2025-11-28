// Ordenação rápida - quicksort
#include <stdio.h>

int particao(int e, int d, int v[]){
    int pivo = v[d];
    int j = e - 1;
    int i;
    for (i = 0; i < d; i++){
        if (v[i] <= pivo){
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


void quicksort(int i, int f, int v){
    if (i < f){
        int p = particao(i, f, v);
        quicksort(i, p-1, v);
        quicksort(p + 1, f, v);
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
    quicksort(0, n-1, v);
    printf("Inprimindo o resultado:\n");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}