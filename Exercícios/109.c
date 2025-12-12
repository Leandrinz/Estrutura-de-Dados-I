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

void mostrar(Fila *f) {
    No *aux = f->inicio;

    if (aux == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }

    printf("\n--- Jogadores na fila ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nickname: %s\n", aux->dado.id, aux->dado.nickname);
        aux = aux->prox;
    }
}

int main() {
    Fila fila;
    inicializar(&fila);

    int opc = -1;

    while (opc != 3) {
        printf("\n1. Adicionar Jogador na Fila\n");
        printf("2. Mostrar Fila\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Jogador j;
            printf("ID do jogador: ");
            scanf("%d", &j.id);
            printf("Nickname: ");
            scanf("%s", j.nickname);
            inserir(&fila, j);
        } else if (opc == 2) {
            mostrar(&fila);
        }
    }

    return 0;
}
