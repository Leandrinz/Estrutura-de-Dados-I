// Mostrando uma lista encadeada
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
    printf("1 - Adicionar aluno\n");
    printf("2 - Mostrar lista\n");
    printf("3 - Sair\n");
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

void mostrar(Lista lista){
    struct No * pi = lista.inicio;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }
        if (op == 2){
            mostrar(lista);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}