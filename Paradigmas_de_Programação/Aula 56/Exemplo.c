// Recursividade
#include <stdio.h>
// Recursividade é tipo dividir um problema maior em problemas menores
int soma (int n){
    if (n == 1){
        return 1;
    }
    return n + soma(n - 1); // Ela quebra o problema de 'somar até n' em um problema menor ('somar até n-1') e adiciona o `n` atual ao resultado.
}

int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int r = soma(n);
    printf("%d\n", r);
    return 0;
}