#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Aventureiro;

struct No {
    Aventureiro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("\n==== MENU ====\n");
    printf("1 - Adicionar Aventureiro\n");
    printf("2 - Mostrar Grupo\n");
    printf("3 - Sair\n");
    printf("==============\n");
}

void inserir_inicio(Lista *lista, Aventureiro a) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->dado = a;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void mostrar_grupo(Lista lista) {
    struct No *p = lista.inicio;

    if (p == NULL) {
        printf("O grupo está vazio.\n");
        return;
    }

    printf("\n=== GRUPO DE AVENTUREIROS ===\n");

    while (p != NULL) {
        printf("ID: %d | Nome: %s\n", p->dado.id, p->dado.nome);
        p = p->prox;
    }
}

int main() {
    Lista grupo;
    grupo.inicio = NULL;

    int op;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            Aventureiro a;
            printf("Informe o ID: ");
            scanf("%d", &a.id);

            printf("Informe o nome: ");
            scanf("%s", a.nome);

            inserir_inicio(&grupo, a);
        }

        else if (op == 2) {
            mostrar_grupo(grupo);
        }

    } while (op != 3);

    printf("Programa encerrado.\n");
    return 0;
}
