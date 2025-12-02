#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Jogador;

struct No {
    Jogador dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Matchmaking ===\n");
    printf("1 - Adicionar jogador ao fim da fila\n");
    printf("2 - Iniciar partida (remover primeiro)\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Sair\n");
    printf("===================\n");
}

void ler(Jogador *p) {
    scanf("%d %[^\n]", &p->id, p->nome);
}

void inserir_fim(Lista *l, Jogador j) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = j;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        struct No *pi;
        for (pi = l->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

int remover_inicio(Lista *l) {
    if (l->inicio == NULL) return 0;

    struct No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);

    return 1;
}

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox)
        printf("%d %s\n", pi->dado.id, pi->dado.nome);
}

int main() {
    Lista lista;
    lista.inicio = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 4) {

        if (op == 1) {
            Jogador j;
            ler(&j);
            inserir_fim(&lista, j);
        }

        if (op == 2) {
            if (!remover_inicio(&lista))
                printf("Nao ha jogadores na fila.\n");
        }

        if (op == 3) {
            mostrar(lista);
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}
