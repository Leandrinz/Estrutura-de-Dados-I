#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Definição das Estruturas ---
typedef struct {
    int id;
    char nome[50];
} Heroi;

typedef struct no {
    Heroi heroi;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

// --- Protótipos das Funções ---
void inicializar_lista(Lista *lista);
void adicionar_heroi(Lista *lista, Heroi h);
void dispensar_heroi(Lista *lista, int id);
void mostrar_guilda(Lista *lista);
void menu();

// --- Função Principal ---
int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_heroi;
    Heroi novo_heroi;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do novo heroi: ");
                scanf("%d", &novo_heroi.id);
                printf("Digite o nome do novo heroi: ");
                scanf("%49s", novo_heroi.nome);
                adicionar_heroi(&guilda, novo_heroi);
                break;
            case 2:
                mostrar_guilda(&guilda);
                break;
            case 3:
                printf("\nDigite o ID do heroi a ser dispensado: ");
                scanf("%d", &id_heroi);
                dispensar_heroi(&guilda, id_heroi);
                printf("\n--- Roster da Guilda Atualizado ---\n");
                mostrar_guilda(&guilda);
                break;
            case 4:
                printf("\nSaindo do gerenciador da guilda...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 4);

    // Liberar memória restante (boa prática)
    while(guilda.inicio != NULL) {
        No *temp = guilda.inicio;
        guilda.inicio = guilda.inicio->prox;
        free(temp);
    }

    return 0;
}

// --- Implementação das Funções Auxiliares ---
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

// Insere um novo herói no final da lista.
void adicionar_heroi(Lista *lista, Heroi h) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->heroi = h;
        novo->prox = NULL;

        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            No *aux = lista->inicio;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } else {
        printf("Erro de alocacao de memoria!\n");
    }
}

void mostrar_guilda(Lista *lista) {
    printf("\n--- Roster da Guilda ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("ID: %d, Nome: %s\n", aux->heroi.id, aux->heroi.nome);
            aux = aux->prox;
        }
    }
    printf("------------------------\n");
}

void menu() {
    printf("\nGerenciador de Guilda:\n");
    printf("1. Adicionar Heroi\n");
    printf("2. Mostrar Guilda\n");
    printf("3. Dispensar Heroi por ID\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para deletar um nó baseado no ID do herói.
void dispensar_heroi(Lista *lista, int id) {
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia. Nao e possivel dispensar.\n");
        return;
    }

    No *ant = NULL;
    No *aux = lista->inicio;

    while (aux != NULL && aux->heroi.id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Heroi com ID %d nao encontrado.\n", id);
        return;
    }

    if (ant == NULL) {
        // remover primeiro
        lista->inicio = aux->prox;
    } else {
        // remover do meio ou fim
        ant->prox = aux->prox;
    }

    printf("Heroi dispensado: ID: %d, Nome: %s\n", aux->heroi.id, aux->heroi.nome);
    free(aux);
}
