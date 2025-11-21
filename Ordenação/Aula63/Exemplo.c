// Inserindo um item na posição correta de um vetor ordenado
#include <stdio.h>


int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int i;
    int v[n + 1];
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int x;
    scanf("%d", &x);
    // Ordenação por inserção
    for (i = n - 1; i >= 0 && x < v[i]; i--){
        v[i + 1] = v[i];
    }
    v[i + 1] = x;
    printf("Imprimindo o vetor\n");
    for (i = 0; i < n + 1; i++){
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}