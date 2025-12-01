#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[100];
    char status[50];
} Missao;

typedef struct No {
    Missao dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void iniciar(Lista *l) {
    l->inicio = NULL;
}

void adicionar_missao(Lista *l, Missao m) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

No* pesquisar_missao(Lista *l, int id) {
    No *aux = l->inicio;
    while (aux != NULL) {
        if (aux->dado.id == id) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void mostrar_missoes(Lista *l) {
    No *aux = l->inicio;
    if (aux == NULL) {
        printf("Nenhuma missao cadastrada.\n");
        return;
    }
    while (aux != NULL) {
        printf("ID: %d | Titulo: %s | Status: %s\n", aux->dado.id, aux->dado.titulo, aux->dado.status);
        aux = aux->prox;
    }
}

int main() {
    Lista diario;
    iniciar(&diario);

    int opcao;

    do {
        printf("\n1 - Adicionar Missao\n");
        printf("2 - Mostrar Missoes\n");
        printf("3 - Buscar Missao por ID\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Missao m;
            printf("ID da Missao: ");
            scanf("%d", &m.id);
            getchar();

            printf("Titulo: ");
            fgets(m.titulo, 100, stdin);
            m.titulo[strcspn(m.titulo, "\n")] = '\0';

            printf("Status: ");
            fgets(m.status, 50, stdin);
            m.status[strcspn(m.status, "\n")] = '\0';

            adicionar_missao(&diario, m);

        } else if (opcao == 2) {
            mostrar_missoes(&diario);

        } else if (opcao == 3) {
            int id;
            printf("Digite o ID: ");
            scanf("%d", &id);

            No *res = pesquisar_missao(&diario, id);

            if (res == NULL) {
                printf("Missao nao encontrada!\n");
            } else {
                printf("ID: %d\n", res->dado.id);
                printf("Titulo: %s\n", res->dado.titulo);
                printf("Status: %s\n", res->dado.status);
            }
        }

    } while (opcao != 4);

    return 0;
}
