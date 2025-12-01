#include <stdio.h>
#include "estudante.h"
#include <stdlib.h>

struct estudante{
    int mat;
    char nome[50];
    float n1;
    float n2;
    float n3;
};

Estudante* cria(int n){
    Estudante *v = (Estudante *) malloc(n * sizeof(Estudante));
}

void ler(int n, Estudante *v){
    printf("Informe os dados dos estudantes:\n");
    int i;
    for (i = 0; i < n; i++){
        scanf("%d %s %f %f %f", &v[i].mat, v[i].nome, &v[i].n1, &v[i].n2, &v[i].n3);
    }
}

void media(int n, Estudante *v){
    printf("Imprimindo as medias:\n");
    int i;
    for (i = 0; i < n; i++){
        float media = (v[i].n1 + v[i].n2 + v[i].n3) / 3;
        printf("%S:%.2f\n", v[i].nome, media);
    }
}