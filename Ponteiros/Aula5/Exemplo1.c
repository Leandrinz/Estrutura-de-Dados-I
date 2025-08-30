#include <stdio.h>

int main(){
    int n;
    int *pn = &n;
    printf("Informe a quantidade de valores: ");
    scanf("%d", pn);
    int v[n];
    int *pv1 = v; // Não colocamos & por que o vetor em si já é um endereço!
    // O vetor é o primeiro endereço de onde o primeiro elemento do vetor começa
    int *pv2 = &v[0]; 
    int i;
    if (pv1 == pv2){
        printf("Iguais\n");
    }
    else{
        printf("Diferentes");
    }
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++){
        if (v[i] % 2 == 0){
            printf("Par\n");
        }
        else{
            printf("Impar\n");
        }
    }
    return 0;
}