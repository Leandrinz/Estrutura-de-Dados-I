// Ordenação por inserção de estruturas
#include <stdio.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

int main(){ 
    int n;
    printf("Informe o valor de N:\n");
    scanf("%d", &n);
    int i, j;
    estudante v[n];
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    for (i = 1; i < n; i++){
        estudante x = v[i];
        for (j = i - 1; j >= 0 && x.mat < v[j].mat; j--){
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
    for (i = 0; i < n; i++){
        printf("%s:%d\n", v[i].nome, v[i].mat);
    }
    printf("\n");
    return 0;
}