#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Heroi;

struct No {
    Heroi dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Adicionar heroi no fim\n");
    printf("2 - Inserir guarda-costas antes do VIP\n");
    printf("3 - Mostrar formacao\n");
    printf("4 - Sair\n");
    printf("=========================\n");
}

void ler(Heroi *h) {
    scanf("%d %[^\n]", &h->id, h->nome);
}

void inserir_fim(Lista *lista, Heroi h) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = h;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

struct No* inserir_antes(Lista *lista, Heroi novoHeroi, int idVip) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    if (lista->inicio->dado.id == idVip) {
        struct No *novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = novoHeroi;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return novo;
    }

    struct No *ant = NULL;
    struct No *pi = lista->inicio;

    while (pi != NULL && pi->dado.id != idVip) {
        ant = pi;
        pi = pi->prox;
    }

    if (pi == NULL) {
        return NULL;
    }

    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = novoHeroi;
    novo->prox = pi;
    ant->prox = novo;
    return novo;
}

void mostrar(Lista lista) {
    struct No *pi;
    printf("=== Formacao ===\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    printf("================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 4) {

        if (op == 1) {
            Heroi h;
            ler(&h);
            inserir_fim(&lista, h);
        }

        if (op == 2) {
            Heroi guarda;
            printf("Informe ID e nome do guarda-costas:\n");
            ler(&guarda);

            int vip;
            printf("Informe o ID do VIP:\n");
            scanf("%d", &vip);

            struct No *pi = inserir_antes(&lista, guarda, vip);
            if (pi == NULL) {
                printf("Nao foi possivel inserir. VIP nao encontrado.\n");
            }
        }

        if (op == 3) {
            mostrar(lista);
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}
