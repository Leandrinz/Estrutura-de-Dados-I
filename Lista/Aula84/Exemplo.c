// Inserindo um item no fim de uma lista encadeada
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

struct No{
    estudante dado;
    struct No * prox;
};

typedef struct {
    struct No *inicio;
}Lista;

void menu(){
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Inserir inicio\n");
    printf("2 - Inserir no fim\n");
    printf("3 - Mostrar lista\n");
    printf("4 - Pesquisar por matricula\n");
    printf("5 - Sair\n");
    printf("=========================\n");
}

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir_inicio(Lista *plista, estudante dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, estudante dado){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void mostrar(Lista lista){
    struct No * pi = lista.inicio;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

struct No* pesquiar (Lista lista, int mat){
    struct No * pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    return pi;
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 5){
        if (op == 1){
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if (op == 2){
            estudante e;
            ler(&e);
            inserir_fim(&lista, e);
        }
        if (op == 3){
            mostrar(lista);
        }
        if (op == 4){
            int mat;
            printf("Informe a matricula\n");
            scanf("%d", &mat);
            struct No * pi = pesquisar(lista, mat);
            if (pi != NULL){
                printf("%d %s\n", pi->dado.mat, pi->dado.nome);
            }
            else{
                printf("Estudante nao encontrado\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}