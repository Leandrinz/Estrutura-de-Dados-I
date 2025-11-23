//  Paradigmas de Programação - Divisão e Conquista
// Basicamente divide um problema em partes menores
#include <stdio.h>

int pares(int i, int f, int v[]){
    if (i < f){
        int m = (i + f)/ 2;
        int e = pares(i, m, v);
        int d = pares(m + 1, f, v);
        return e + d;
    }
    if (v[i] % 2 == 0) return 1;
    return 0;
}

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int r = pares(0, n - 1, v);
    printf("%d", r);
    return 0;
}