// Adicionando um elemento a uma fila
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

struct no{
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct 
{
    No * inicio;
    No * fim;
}Fila;

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir(Fila *pfila, estudante dado){
    No * novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if (pfila->inicio == NULL){
        pfila->inicio = novo;
        pfila->fim = novo;
    }
    else{
        pfila->fim->prox = novo;
        pfila->fim = novo;
    }
}

void mostrar(Fila fila){
    No * pi;
    for (pi = fila.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

void menu(){
    printf("=== escolha uma opcao === \n");
    printf("1 - inserir\n");
    printf("2 - Mostrar\n");
    printf("3 - Remover\n");
    printf("4 - sair \n");
    printf("=========================");
}

void remover(Fila *pfila){
    if (pfila->inicio == NULL){
        printf("A fila esta vazia\n");
    }
    else if (pfila->inicio->prox == NULL){
        pfila->inicio = NULL;
        pfila->fim = NULL;
    }
    else{
        No * pi = pfila->inicio;
        pfila->inicio = pi->prox;
        free(pi);
    }
}


int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 4){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante:\n");
            ler(&e);
            inserir(&fila, e);
        }
        else if(op == 2){
            mostrar(fila);
        }
        else if(op == 3){
            remover(&fila);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}