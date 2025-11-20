// Recursividade com mais de uma chamada a função
#include <stdio.h>

int f(int n){
    if (n == 1){
        return 0;
    }
    if (n == 2){
        return 1;
    }
    return f(n - 1) + f(n- 2); // Chamada múltipla da função dentro da própria função
}

int main(){
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int numero = f(n);
    printf("%d", numero);
    return 0;
}