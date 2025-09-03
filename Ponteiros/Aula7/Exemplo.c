// Lendo um vetor em uma função usando aritmética de ponteiros

#include <stdio.h>


void ler(int n, int v[]){
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", v + i);
    }
}


int main(){
    int n;
    int *pn = &n;
    printf("Informe a quantidade de valores que deseja ler: \n");
    scanf("%d", pn);
    int v[n];
    ler(n,v);
    int temp = v[0];
    v[0] = v[n - 1];
    v[n - 1] = temp;
    int i;
    for (i = 0; i < n; i++){
        printf("%d", v[i]);
    }
    printf("\n");


    return 0;
}