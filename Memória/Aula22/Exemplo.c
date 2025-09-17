// Alocação de Memória - vetor
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Informe a quantidade de valores: \n");
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int)); // Aqui usamo o n * sizeof, pq se trata de um vetor que conterá n espaços
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int maior = v[0];
    for (i = 1; i < n; i++){
        if (maior < v[i]){
            maior = v[i];
        }
    }
    printf("%d", maior);
    return 0;
}