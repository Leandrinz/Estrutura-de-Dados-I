// Alocação de Memória - calloc //
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    int *vetor = (int *) calloc(n, sizeof(int)); // No calloc passamos o número de elementos e o tamanho (em bytes) de cada elemento.
    for (int contador = 0; contador < n; contador++){
        scanf("%d", &vetor[contador]);
        if (vetor[contador] < 0){
            vetor[contador] = 2;
        }
    }
    for (int contador = 0; contador < n; contador++){
        printf("%d ", vetor[contador]);
    }
    free(vetor);
    return 0;
}

// DIFERENÇA DO MALLOC PRO CALLOC: 
    // calloc inicializa a memória alocada com zeros, enquanto malloc não garante a inicialização (deixando "lixo de memória").