#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[50];
} estudante;

struct No {
    estudante dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

void menu() {
    printf("=== Escolha uma opcao ===\n");
    printf("1 - Inserir inicio\n");
    printf("2 - Inserir fim\n");
    printf("3 - Mostrar lista\n");
    printf("4 - Pesquisar por matricula\n");
    printf("5 - Inserir apos\n");
    printf("6 - Deletar inicio\n");
    printf("7 - Deletar por matricula\n");
    printf("8 - Deletar fim\n");
    printf("9 - Sair\n");
    printf("=========================\n");
}

void ler(estudante *pe) {
    scanf("%d %s", &pe->mat, pe->nome);
}

void inserir_inicio(Lista *plista, estudante dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, estudante dado) {
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

void mostrar(Lista lista) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox)
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
}

struct No* pesquisar(Lista lista, int mat) {
    struct No *pi;
    for (pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
    return pi;
}

struct No* inserir_apos(Lista *plista, estudante dado, int mat) {
    struct No *pi;
    for (pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);

    if (pi == NULL)
        return NULL;

    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = dado;
    novo->prox = pi->prox;
    pi->prox = novo;
    return pi;
}

void deletar_inicio(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    struct No *temp = plista->inicio;
    plista->inicio = plista->inicio->prox;
    free(temp);
}

void deletar_mat(Lista *plista, int mat) {
    if (plista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    struct No *pi = plista->inicio;
    struct No *ant = NULL;

    while (pi != NULL && pi->dado.mat != mat) {
        ant = pi;
        pi = pi->prox;
    }

    if (pi == NULL) {
        printf("Nao encontrado\n");
        return;
    }

    if (ant == NULL) {
        plista->inicio = plista->inicio->prox;
    } else {
        ant->prox = pi->prox;
    }

    free(pi);
}

void deletar_fim(Lista *plista) {

    if (plista->inicio == NULL) {
        printf("Nao e possivel remover. A lista esta vazia.\n");
        return;
    }

    if (plista->inicio->prox == NULL) {
        struct No *temp = plista->inicio;
        plista->inicio = NULL;
        free(temp);
        return;
    }

    struct No *ant = plista->inicio;
    struct No *atual = plista->inicio->prox;

    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = NULL;
    free(atual);
}

int main() {
    Lista lista;
    lista.inicio = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 9) {

        if (op == 1) {
            estudante e;
            ler(&e);
            inserir_inicio(&lista, e);
        }

        if (op == 2) {
            estudante e;
            ler(&e);
            inserir_fim(&lista, e);
        }

        if (op == 3) {
            mostrar(lista);
        }

        if (op == 4) {
            int mat;
            scanf("%d", &mat);
            struct No *pi = pesquisar(lista, mat);
            if (pi == NULL)
                printf("Nao encontrado\n");
            else
                printf("%d %s\n", pi->dado.mat, pi->dado.nome);
        }

        if (op == 5) {
            estudante e;
            ler(&e);
            int mat;
            scanf("%d", &mat);
            struct No *pi = inserir_apos(&lista, e, mat);
            if (pi == NULL)
                printf("Nao foi possivel inserir\n");
        }

        if (op == 6) {
            deletar_inicio(&lista);
        }

        if (op == 7) {
            int mat;
            scanf("%d", &mat);
            deletar_mat(&lista, mat);
        }

        if (op == 8) {
            deletar_fim(&lista);
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}
