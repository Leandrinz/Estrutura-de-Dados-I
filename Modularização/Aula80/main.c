#include <stdio.h>
#include "estudante/estudante.h"

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    Estudante *v = cria(n);
    ler(n, v);
    media(n, v);
    return 0;
}