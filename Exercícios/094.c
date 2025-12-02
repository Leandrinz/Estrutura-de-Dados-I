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

// -------- Funções --------

void inicializar(Lista *l) {
    l->inicio = NULL;
}

void inserir(Lista *l) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));

    printf("Digite o ID do mercenario: ");
    scanf("%d", &novo->dado.id);
    getchar();

    printf("Digite o nome do mercenario: ");
    fgets(novo->dado.nome, 100, stdin);
    novo->dado.nome[strcspn(novo->dado.nome, "\n")] = '\0';

    novo->prox = l->inicio;
    l->inicio = novo;

    printf("Mercenario inserido com sucesso!\n");
}

void mostrar(Lista *l) {
    struct No *aux = l->inicio;

    if (aux == NULL) {
        printf("Nenhum mercenario registrado!\n");
        return;
    }

    printf("\n--- Mercenarios Registrados ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
}

void buscar(Lista *l) {
    int id;
    printf("Digite o ID para buscar: ");
    scanf("%d", &id);

    struct No *aux = l->inicio;

    while (aux != NULL) {
        if (aux->dado.id == id) {
            printf("Mercenario encontrado! Nome: %s\n", aux->dado.nome);
            return;
        }
        aux = aux->prox;
    }

    printf("Mercenario nao encontrado!\n");
}

int tamanho(Lista *l) {
    int cont = 0;
    struct No *aux = l->inicio;

    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }

    return cont;
}

// -------- Programa Principal --------

void menu() {
    printf("\n======== GUILDA DE MERCENARIOS ========\n");
    printf("1 - Adicionar mercenario\n");
    printf("2 - Mostrar mercenarios\n");
    printf("3 - Buscar por ID\n");
    printf("4 - Mostrar tamanho da guilda\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main() {
    Lista lista;
    inicializar(&lista);

    int op;

    do {
        menu();
        scanf("%d", &op);
        getchar(); // limpar buffer

        switch(op) {
            case 1:
                inserir(&lista);
                break;
            case 2:
                mostrar(&lista);
                break;
            case 3:
                buscar(&lista);
                break;
            case 4:
                printf("A guilda possui %d mercenarios.\n", tamanho(&lista));
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}
