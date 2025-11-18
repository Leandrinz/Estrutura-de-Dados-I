#include <stdio.h>

int main(){
    int n;
    printf("Informe o valor de n\n");
    scanf("%d", &n);
    int i;
    for (i = n; i > 1; i/2);
    printf("%d", i);

    return 0;
}
// Resumo: Temos um tempo quadrático Porque o número de operações cresce de forma muito lenta, proporcionalmente ao logaritmo do tamanho da entrada 'n'.