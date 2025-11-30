// Separação do programa em arquivos com estruturas
#include <stdio.h>
#include "estudante/estudante.h"
#include <stdlib.h>

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);

    Estudante *v = cria(n);

    if (v == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    ler(n, v);
    imprimir(n, v);

    free(v); // sempre bom liberar a memória alocada
    return 0;
}
