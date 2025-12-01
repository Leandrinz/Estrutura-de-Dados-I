#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = NULL;
}

void inserirInicio(Fila *f, Jogador j) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = j;
    novo->prox = f->inicio;
    f->inicio = novo;
}

void inserirFim(Fila *f, Jogador j) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        No *aux = f->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void mostrarFila(Fila *f) {
    No *aux = f->inicio;
    if (aux == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    while (aux != NULL) {
        printf("Matricula: %d | Nome: %s\n", aux->dado.mat, aux->dado.nome);
        aux = aux->prox;
    }
}

int main() {
    Fila f;
    iniciarFila(&f);
    int op;

    do {
        printf("\n1 - Adicionar no inicio\n");
        printf("2 - Adicionar no fim\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        if (op == 1 || op == 2) {
            Jogador j;
            printf("Matricula: ");
            scanf("%d", &j.mat);
            getchar();
            printf("Nome: ");
            fgets(j.nome, 50, stdin);
            j.nome[strcspn(j.nome, "\n")] = '\0';

            if (op == 1) inserirInicio(&f, j);
            else inserirFim(&f, j);
        } else if (op == 3) {
            mostrarFila(&f);
        }

    } while (op != 4);

    return 0;
}
