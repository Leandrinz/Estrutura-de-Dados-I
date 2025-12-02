#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Mercenario;

struct No {
    Mercenario dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

// -------------------- Funções ---------------------

void inserir_fim(Lista *l) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));

    printf("ID do mercenario: ");
    scanf("%d", &novo->dado.id);

    printf("Nome do mercenario: ");
    scanf(" %[^\n]", novo->dado.nome);

    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        return;
    }

    struct No *aux = l->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

void mostrar(Lista *l) {
    if (l->inicio == NULL) {
        printf("\nA companhia está vazia.\n");
        return;
    }

    printf("\n--- Mercenarios da Companhia ---\n");
    struct No *aux = l->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
}

void demitir_todos_mercenarios(Lista *l) {
    if (l->inicio == NULL) {
        printf("\nNão há mercenarios para demitir.\n");
        return;
    }

    struct No *aux = l->inicio;

    while (aux != NULL) {
        struct No *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    l->inicio = NULL;

    printf("\nTodos os mercenarios foram demitidos. A lista está vazia.\n");
}

// ---------------------- MAIN -----------------------

int main() {
    Lista companhia;
    companhia.inicio = NULL;

    int op;

    do {
        printf("\n===== Companhia Mercenaria =====\n");
        printf("1. Contratar mercenario\n");
        printf("2. Exibir companhia\n");
        printf("3. Declarar falencia (demitir todos)\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                inserir_fim(&companhia);
                break;
            case 2:
                mostrar(&companhia);
                break;
            case 3:
                demitir_todos_mercenarios(&companhia);
                break;
            case 4:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (op != 4);

    // Garantir que memória será liberada ao sair
    demitir_todos_mercenarios(&companhia);

    return 0;
}
