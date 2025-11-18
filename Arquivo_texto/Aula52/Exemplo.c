#include <stdio.h>

int main(){
    int n;
    printf("Informe o tamanho da matriz\n");
    scanf("%d", &n);
    int m[n][n];
    int i, j;
    for (i = 0; i < n; i++){
        for (i = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    int soma = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i < j){
                soma = soma + m[i][j];
            }
        }
    }
    printf("Soma:%d", soma);

    return 0;
}
// Resumo do tempo quadrático (O(n²)): O tempo de execução cresce de forma proporcional ao quadrado do tamanho da entrada 'n'.
// Os responsáveis pela complexidade são os dois for alinhados.