#include <stdio.h>

int somatorio(int i, int n, int v[]){
    if (i == n){
        return 0;
    }
    if (v[i] > 0){
        return 1 + somatorio(i + 1, n, v);
    }
    return 0;
}

int main(){
    int n;
    printf("Digite o valor de N:\n");
    scanf("%d", &n);
    int i;
    int v[n];
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int total_cristal_positivo = somatorio(0, n, v);
    printf("O total de cristais eh igual a:%d", total_cristal_positivo);
    return 0;
}