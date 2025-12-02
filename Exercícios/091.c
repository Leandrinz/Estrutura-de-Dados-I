#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ESTRUTURAS ---
typedef struct {
    int id;
    char descricao[100];
} Etapa;

typedef struct No {
    Etapa etapa;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

// --- PROTÓTIPOS ---
void menu();
void inserir_fim(Lista *lista, Etapa e);
void mostrar(Lista lista);
void deletar_antes(Lista *lista, int id_ref);

// --- FUNÇÃO PRINCIPAL ---
int main() {
    Lista lista;
    lista.inicio = NULL;
    int op, id_ref;
    Etapa e;

    do {
        menu();
        scanf("%d", &op);
        getchar(); // Limpa o buffer do teclado

        switch(op) {
            case 1:
                printf("\nDigite o ID da etapa: ");
                scanf("%d", &e.id);
                getchar();
                printf("Digite a descricao da etapa: ");
                fgets(e.descricao, 100, stdin);
                e.descricao[strcspn(e.descricao, "\n")] = 0;
                inserir_fim(&lista, e);
                break;

            case 2:
                mostrar(lista);
                break;

            case 3:
                printf("\nInforme o ID da etapa de referencia: ");
                scanf("%d", &id_ref);
                deletar_antes(&lista, id_ref);
                break;

            case 4:
                printf("\nFinalizando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 4);

    // Liberar memória antes de sair
    No *atual = lista.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---
void menu() {
    printf("\n--- Gerenciador de Etapas de Missao ---\n");
    printf("1 - Inserir etapa no fim\n");
    printf("2 - Mostrar etapas\n");
    printf("3 - Deletar etapa ANTES de um ID\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

void inserir_fim(Lista *lista, Etapa e) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->etapa = e;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *pi = lista->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
    printf("Etapa '%s' inserida com sucesso!\n", e.descricao);
}

void mostrar(Lista lista) {
    printf("\n--- Diário de Missao ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhuma etapa registrada.\n");
        return;
    }
    No *pi = lista.inicio;
    while (pi != NULL) {
        printf("ID: %d - Descricao: %s\n", pi->etapa.id, pi->etapa.descricao);
        pi = pi->prox;
    }
    printf("------------------------\n");
}

void deletar_antes(Lista *lista, int id_ref) {
    // 1. Lista vazia
    if (lista->inicio == NULL) {
        printf("\nA lista esta vazia. Nao ha etapas para deletar.\n");
        return;
    }

    No *ant = NULL;            // anterior ao que será removido
    No *atual = lista->inicio; // candidato a remoção
    No *prox = atual->prox;    // etapa de referência

    // 5. Procurar ID de referência
    while (prox != NULL && prox->etapa.id != id_ref) {
        ant = atual;
        atual = prox;
        prox = prox->prox;
    }

    // Se não encontrou o ID
    if (prox == NULL) {
        printf("\nEtapa de referencia (ID %d) nao encontrada.\n", id_ref);
        return;
    }

    // 2. Referência é a primeira etapa
    if (lista->inicio->etapa.id == id_ref) {
        printf("\nA etapa de referencia eh a primeira. Nao ha etapa anterior para remover.\n");
        return;
    }

    // 3. Remover a primeira etapa (referência é a segunda)
    if (ant == NULL) {
        lista->inicio = prox;
        printf("\nEtapa deletada -> ID: %d, Desc: %s\n",
               atual->etapa.id, atual->etapa.descricao);
        free(atual);
        return;
    }

    // 4. Caso geral (meio da lista)
    ant->prox = prox;
    printf("\nEtapa deletada -> ID: %d, Desc: %s\n",
           atual->etapa.id, atual->etapa.descricao);
    free(atual);
}
