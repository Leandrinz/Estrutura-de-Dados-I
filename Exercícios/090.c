#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estruturas ---
typedef struct {
    int id;
    char nome[100];
} Ward;

typedef struct no {
    Ward ward;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
} Lista;


// --- Funções ---
void inicializar(Lista *l) {
    l->inicio = NULL;
}

void adicionar_ward(Lista *l, Ward w) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        printf("Erro de memória!\n");
        return;
    }

    novo->ward = w;
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

void deletar_apos(Lista *l, int id) {
    if (l->inicio == NULL) {
        printf("\nNenhum ward ativo. Lista vazia.\n");
        return;
    }

    No *aux = l->inicio;

    // Procurar o ward com o ID
    while (aux != NULL && aux->ward.id != id) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("\nWard com ID %d nao encontrado.\n", id);
        return;
    }

    if (aux->prox == NULL) {
        printf("\nEste ward eh o ultimo. Nao ha ward apos ele para destruir.\n");
        return;
    }

    // Deletar o nó seguinte
    No *temp = aux->prox;
    aux->prox = temp->prox;

    printf("\nWard destruido -> ID: %d, Nome: %s\n", temp->ward.id, temp->ward.nome);
    free(temp);
}

void mostrar(Lista *l) {
    printf("\n--- Wards Ativos ---\n");

    if (l->inicio == NULL) {
        printf("Nenhum ward ativo.\n");
        return;
    }

    No *aux = l->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->ward.id, aux->ward.nome);
        aux = aux->prox;
    }
}

void menu() {
    printf("\n===== Sistema de Wards =====\n");
    printf("1. Adicionar Ward\n");
    printf("2. Ward Shatter (deletar apos ID)\n");
    printf("3. Mostrar Wards Ativos\n");
    printf("4. Sair\n");
    printf("Escolha: ");
}


// --- Programa Principal ---
int main() {
    Lista wards;
    inicializar(&wards);

    int opcao, id_ref;
    Ward w;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do ward: ");
                scanf("%d", &w.id);

                printf("Digite o nome do ward: ");
                scanf("%99s", w.nome);

                adicionar_ward(&wards, w);
                break;

            case 2:
                printf("\nDigite o ID do ward de referencia: ");
                scanf("%d", &id_ref);

                deletar_apos(&wards, id_ref);
                break;

            case 3:
                mostrar(&wards);
                break;

            case 4:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    // Liberação de memória
    while (wards.inicio != NULL) {
        No *temp = wards.inicio;
        wards.inicio = wards.inicio->prox;
        free(temp);
    }

    return 0;
}
