#include <stdio.h>
#include <stdlib.h>
#include "heroi.h"

struct heroi{
    char nome[50];
    int hp;
    int ataque;
};

Heroi* cria(int n){
    Heroi * v = (Heroi *) malloc(n * sizeof(Heroi));
    return v;
}

void ler(int n, Heroi *v){
    printf("Informe os dados do Heroi:\n");
    int i;
    for (i = 0; i < n; i++){
        scanf("%s %d %d", v[i].nome, &v[i].hp, &v[i].ataque);
    }
}

void imprimir(int n, Heroi *v){
    int i;
    for (i = 0; i < n; i++){
        printf("Nome:%s\nHp:%d\nAtaque:%d\n", v[i].nome, v[i].hp, v[i].ataque);
        printf("\n");
    }
}