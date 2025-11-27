// Algoritmos de partição do próprio vetor
#include <stdio.h>

void particao(int n, int v[]){
    int pivo = v[n - 1];
    int j = -1;
    int i;
    for (i = 0; i < n - 1; i++){
        if (v[i] < pivo){
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[j + 1];
    v[j + 1] = v[n - 1];
    v[n - 1] = temp;
}

int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0;  i < n; i++){
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("Imprimindo o vetor particionado:\n");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}