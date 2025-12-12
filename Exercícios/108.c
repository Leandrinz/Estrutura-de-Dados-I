#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(Fila *f, Jogador j) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("Jogador %s (ID %d) adicionado à fila!\n", j.nickname, j.id);
}

void exibir(Fila *f) {
    No *aux = f->inicio;
    if (!aux) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\n--- Jogadores na fila ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nick: %s\n", aux->dado.id, aux->dado.nickname);
        aux = aux->prox;
    }
}

int main() {
    Fila matchmaking;
    inicializar(&matchmaking);

    int opc = -1;

    while (opc != 0) {
        printf("\n===== MENU MATCHMAKING =====\n");
        printf("1 - Inserir jogador\n");
        printf("2 - Exibir fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Jogador j;
            printf("ID do jogador: ");
            scanf("%d", &j.id);
            printf("Nickname: ");
            scanf("%s", j.nickname);
            inserir(&matchmaking, j);
        } else if (opc == 2) {
            exibir(&matchmaking);
        }
    }

    return 0;
}
