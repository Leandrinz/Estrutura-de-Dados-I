// Verificando se a pilha esta vazia
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
    printf("3 - Remover\n");
    printf("4 - vazia\n");
    printf("5 - Sair\n");
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
// pop
void remover(Pilha *ppilha){
    if (ppilha->topo == NULL){
        printf("A pilha esta vazia\n");
    }
    else{
        No * pi = ppilha->topo;
        ppilha->topo = pi->prox;
        free(pi);
    }
}
// is empyt
int vazia(Pilha pilha){
    if (pilha.topo == NULL){
        return 1;
    }
    else {
        return 0;
    }
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
    while (op != 5){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante\n");
            ler(&e);
            inserir(&pilha, e);
        }
        else if (op == 2){
            mostrar_pilha(pilha);
        }
        else if (op == 3){
            remover(&pilha);
        }
        else if (op == 4){
            int r;
            r = vazia(pilha);
            if (r == 1){
                printf("Pilha esta vazia\n");
            }
            else{
                printf("A pilha nao esta vazia\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}