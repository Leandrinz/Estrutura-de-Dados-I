// Inserindo um item após um dado nó em uma lista encadeada
// Inserindo um item no fim de uma lista encadeada
#include <stdio.h>
#include <stdlib.h>

typedef struct {
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
    printf("3 - Inserir antes");
    printf("4 - Inserir apos\n");
    printf("5 - Mostrar lista\n");
    printf("6 - Pesquisar por matricula\n");
    printf("7 - Deletar inicio\n");
    printf("8 - Sair\n");
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

struct No* inserir_apos(Lista *plista, estudante dado, int mat){
    struct No * pi;
    for (pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    if (pi == NULL){
        return pi;
    }
    else{
        struct No *novo = (struct No*) malloc(sizeof(struct No));
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

struct No* inserir_antes(Lista *plista, estudante dado, int mat){
    if (plista->inicio == NULL){
        return NULL;
    }
    else if(plista->inicio->dado.mat == mat){
        struct No* novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = plista->inicio;
        plista->inicio = novo;
    }
    else{
        struct No* pi;
        for (pi = plista->inicio; pi->prox != NULL && pi->prox->dado.mat == mat; pi = pi->prox);
        if (pi->prox == NULL){
            return pi;
        }
        else{
            struct No *novo = (struct No *) malloc(sizeof(struct No));
            novo->dado = dado;
            novo->prox = pi->prox;
            pi->prox = novo;
            return pi;
        }
    }
}

void deletar_inicio(Lista *plista){
    if (plista->inicio == NULL){
        printf("A lista esta vazia\n");
    }
    else{
        struct No * pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
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
    while (op != 8){
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
            estudante e;
            ler (&e);
            int mat;
            printf("Informe a matricula para inserir apos:\n");
            scanf("%d", &mat);
            struct No * pi = inserir_apos(&lista, e, mat);
            if (pi == NULL){
                printf("Não foi possivel inserir o estudante\n");
            }
        }
        if (op == 4){
            estudante e;
            ler(&e);
            printf("Informe a matricula:\n");
            int mat;
            scanf("%d", &mat);
            struct No * pi = inserir_antes(&lista, e, mat);
            if (pi == NULL){
                printf("Nao foi possivel inserir o aluno");
            }
        }
        if (op == 5){
            mostrar(lista);
        }
        if (op == 6){
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
        if (op == 7){
            deletar_inicio(&lista);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}