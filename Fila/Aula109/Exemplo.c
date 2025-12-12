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
    printf("3 - sair \n");
    printf("=========================");
}

int main(){
    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante:\n");
            ler(&e);
            inserir(&fila, e);
        }
        else if(op == 2){
            mostrar(fila);
        }
        menu();
        scanf("%d", &op);
    }
    

    return 0;
}