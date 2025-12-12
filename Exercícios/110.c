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

Jogador remover(Fila *f) {
    Jogador vazio;
    vazio.id = -1;

    if (f->inicio == NULL) {
        printf("A fila esta vazia, nenhum jogador para remover.\n");
        return vazio;
    }

    No *rem = f->inicio;
    Jogador j = rem->dado;

    f->inicio = rem->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(rem);
    return j;
}

int main() {
    Fila fila;
    inicializar(&fila);

    int opc = -1;

    while (opc != 4) {
        printf("\n1. Adicionar Jogador na Fila\n");
        printf("2. Mostrar Fila\n");
        printf("3. Remover Jogador da Fila\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Jogador j;
            printf("ID do jogador: ");
            scanf("%d", &j.id);
            printf("Nickname: ");
            scanf("%s", j.nickname);
            inserir(&fila, j);
        }

        else if (opc == 2) {
            mostrar(&fila);
        }

        else if (opc == 3) {
            Jogador r = remover(&fila);
            if (r.id != -1) {
                printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", r.nickname, r.id);
            }
        }
    }

    return 0;
}
