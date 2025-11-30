#include <stdio.h>
#include "estudante.h"
#include <stdlib.h>

struct estudante{
    int mat;
    char nome[50];
};

Estudante* cria(int n){
    Estudante * v = (Estudante *) malloc(n * sizeof(Estudante));
    return v;
}

void ler(int n, Estudante *v){
    printf("Informe os dados dos estudantes:\n");
    int i;
    for (i = 0; i < n; i++){
        scanf("%d %s", &v[i].mat, v[i].nome);
    }
}

void imprimir(int n, Estudante *v){
    int i;
    for (i = 0; i < n; i++){
        printf("%s:%d\n", v[i].nome, v[i].mat);
    }
}