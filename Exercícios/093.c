#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

struct No {
    Membro dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

// --------------------- FUNÇÕES ----------------------

void inserir_fim(Lista *l) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));

    printf("ID do membro: ");
    scanf("%d", &novo->dado.id);

    printf("Nome do membro: ");
    scanf("%s]", novo->dado.nome);

    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        return;
    }

    struct No *aux = l->inicio;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
}

void mostrar_lista(Lista *l) {
    if (l->inicio == NULL) {
        printf("\nA lista está vazia.\n");
        return;
    }

    struct No *aux = l->inicio;
    printf("\n--- Membros da Guilda ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
}

// Função de pesquisa: retorna o ponteiro para o nó encontrado ou NULL
struct No* pesquisar(Lista *l, int id) {
    struct No *aux = l->inicio;

    while (aux != NULL) {
        if (aux->dado.id == id)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

// Função principal solicitada
void alterar_nome(Lista *l, int id, char novo_nome[]) {
    struct No *membro = pesquisar(l, id);

    if (membro == NULL) {
        printf("\nMembro com ID %d nao encontrado.\n", id);
        return;
    }

    strcpy(membro->dado.nome, novo_nome);
    printf("\nNome atualizado com sucesso!\n");
}

// ------------------------ MAIN ------------------------

int main() {
    Lista guilda;
    guilda.inicio = NULL;

    int opcao, id;
    char novo_nome[100];

    do {
        printf("\n===== Guilda =====\n");
        printf("1. Adicionar membro\n");
        printf("2. Mostrar lista\n");
        printf("3. Alterar nome de membro\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_fim(&guilda);
                break;

            case 2:
                mostrar_lista(&guilda);
                break;

            case 3:
                printf("ID do membro a alterar: ");
                scanf("%d", &id);

                printf("Novo nome: ");
                scanf("%s", novo_nome);

                alterar_nome(&guilda, id, novo_nome);
                break;

            case 4:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}
