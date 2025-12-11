#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome_feitico[50];
    int custo_mana;
}Feitico;

struct no{
    Feitico dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
}Pilha;

void ler(Feitico *pe){
    scanf("%s %d", pe->nome_feitico, &pe->custo_mana);
}

void inserir(Pilha *ppilha, Feitico dado){
    No * novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}


void menu(){
    printf("Escolha a opcao\n");
    printf("1 - Adicionar novo feitico a pilha de comandos\n");
    printf("2 - Finalizar sequencia e sair\n");
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            Feitico f;
            printf("Informe os dados do feitico\n");
            ler(&f);
            inserir(&pilha, f);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}