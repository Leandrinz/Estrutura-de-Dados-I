#include <stdio.h>
#include "heroi/heroi.h"

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);

    Heroi *v = cria(n);

    ler (n, v);
    imprimir(n, v);
    free(v);

    return 0;
}