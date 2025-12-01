#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Item;

struct No {
    Item dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Inserir item no inicio\n");
    printf("2 - Inserir item no fim\n");
    printf("3 - Inserir catalisador apos fragmento\n");
    printf("4 - Mostrar inventario\n");
    printf("5 - Pesquisar por ID\n");
    printf("6 - Sair\n");
    printf("=========================\n");
}

void ler(Item *p) {
    scanf("%d %s", &p->id, p->nome);
}

void inserir_inicio(Lista *plista, Item dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Item dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = NULL;

    if (plista->inicio == NULL) {
        plista->inicio = novo;
    } else {
        struct No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

struct No* inserir_apos(Lista *plista, Item dado, int idFragmento) {
    struct No *pi;
    for (pi = plista->inicio; pi != NULL && pi->dado.id != idFragmento; pi = pi->prox);

    if (pi == NULL) {
        return NULL;
    } else {
        struct No *novo = (struct No*) malloc(sizeof(struct No));
        novo->dado = dado;
        novo->prox = pi->prox;
        pi->prox = novo;
        return pi;
    }
}

void mostrar(Lista lista) {
    struct No *pi = lista.inicio;
    printf("=== Inventario ===\n");
    for (; pi != NULL; pi = pi->prox) {
        printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
    }
    printf("==================\n");
}

struct No* pesquisar(Lista lista, int id) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.id != id; pi = pi->prox);
    return pi;
}

int main() {
    Lista lista;
    lista.inicio = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 6) {
        
        if (op == 1) {
            Item x;
            ler(&x);
            inserir_inicio(&lista, x);
        }

        if (op == 2) {
            Item x;
            ler(&x);
            inserir_fim(&lista, x);
        }

        if (op == 3) {
            Item catalisador;
            printf("ID e nome do catalisador:\n");
            ler(&catalisador);

            int idFrag;
            printf("Inserir apos fragmento de ID:\n");
            scanf("%d", &idFrag);

            struct No *pi = inserir_apos(&lista, catalisador, idFrag);
            if (pi == NULL) {
                printf("Nao foi possivel inserir o catalisador.\n");
            }
        }

        if (op == 4) {
            mostrar(lista);
        }

        if (op == 5) {
            int id;
            printf("Informe o ID:\n");
            scanf("%d", &id);

            struct No *pi = pesquisar(lista, id);

            if (pi != NULL) {
                printf("ID: %d | Nome: %s\n", pi->dado.id, pi->dado.nome);
            } else {
                printf("Item nao encontrado.\n");
            }
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}
