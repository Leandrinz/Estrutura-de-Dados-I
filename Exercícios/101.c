#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome_feitico[50];
    int custo_mana;
} Feitico;

struct no {
    Feitico dado;
    struct no *prox;
};

typedef struct no No;

typedef struct {
    No *topo;
} Pilha;

void ler(Feitico *pe) {
    scanf("%s %d", pe->nome_feitico, &pe->custo_mana);
}

void inserir(Pilha *ppilha, Feitico dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

void menu() {
    printf("Escolha a opcao:\n");
    printf("1 - Adicionar novo feitico à pilha de comandos\n");
    printf("2 - Mostrar pilha de comandos\n");
    printf("3 - Finalizar sequencia e sair\n");
}

void mostrar_pilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }

    No *pi = p->topo;
    printf("\n--- PILHA DE COMANDOS ---\n");
    while (pi != NULL) {
        printf("Feitico: %s | Custo: %d\n", pi->dado.nome_feitico, pi->dado.custo_mana);
        pi = pi->prox;
    }
    printf("-------------------------\n");
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 3) {

        if (op == 1) {
            Feitico f;
            printf("Informe o nome e o custo de mana:\n");
            ler(&f);
            inserir(&pilha, f);
        }
        else if (op == 2) {
            mostrar_pilha(&pilha);
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}
