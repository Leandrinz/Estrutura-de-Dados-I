// Mostrando uma pilha
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[50];
}estudante;

struct no{
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
}Pilha;

void menu(){
    printf("==== escolha uma opcao ====\n");
    printf("1 - adicionar\n");
    printf("2 - Mostrar pilha\n");
    printf("3 - Sair\n");
    printf("===========================\n");
}

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}
//push
void inserir(Pilha *ppilha, estudante dado){
    No * novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

void mostrar_pilha(Pilha pilha){
    No * pi;
    for (pi = pilha.topo; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 3){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante\n");
            ler(&e);
            inserir(&pilha, e);
        }
        else if (op == 2){
            mostrar_pilha(pilha);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}