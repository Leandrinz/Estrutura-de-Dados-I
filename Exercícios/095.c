#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char tipo[50];
} Inimigo;

struct No {
    Inimigo dado;
    struct No *prox;
};

typedef struct {
    struct No *inicio;
} Lista;

// ------------------------ FUNÇÕES ------------------------

void inicializar(Lista *l) {
    l->inicio = NULL;
}

void inserir_fim(Lista *l, Inimigo inimigo) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->dado = inimigo;
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

void exibir(Lista *l) {
    if (l->inicio == NULL) {
        printf("Nenhum inimigo na lista!\n");
        return;
    }

    struct No *aux = l->inicio;
    printf("\n--- Inimigos Atuais ---\n");
    while (aux != NULL) {
        printf("ID: %d | Tipo: %s\n", aux->dado.id, aux->dado.tipo);
        aux = aux->prox;
    }
}

void liberar(Lista *l) {
    struct No *aux = l->inicio;
    while (aux != NULL) {
        struct No *temp = aux->prox;
        free(aux);
        aux = temp;
    }
    l->inicio = NULL;
}

// ---------- FUNÇÃO PRINCIPAL DO EXERCÍCIO ----------

Lista criar_lista(int n) {
    Lista nova;
    inicializar(&nova);

    for (int i = 0; i < n; i++) {
        Inimigo inimigo;

        printf("\nDigite o ID do inimigo %d: ", i + 1);
        scanf("%d", &inimigo.id);
        getchar();

        printf("Digite o tipo do inimigo %d: ", i + 1);
        fgets(inimigo.tipo, 50, stdin);
        inimigo.tipo[strcspn(inimigo.tipo, "\n")] = '\0';

        inserir_fim(&nova, inimigo);
    }

    return nova;
}

// ------------------------ MENU ------------------------

void menu() {
    printf("\n========= GERENCIAMENTO DE INIMIGOS =========\n");
    printf("1 - Exibir inimigos\n");
    printf("2 - Iniciar nova onda\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main() {
    Lista lista_principal;
    inicializar(&lista_principal);

    int op;

    do {
        menu();
        scanf("%d", &op);
        getchar();

        switch (op) {

            case 1:
                exibir(&lista_principal);
                break;

            case 2: {
                int qtd;
                printf("\nQuantos inimigos tera a nova onda? ");
                scanf("%d", &qtd);
                getchar();

                liberar(&lista_principal);  // limpa onda antiga

                lista_principal = criar_lista(qtd);  // cria nova e substitui

                printf("\nNova onda iniciada com sucesso!\n");
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    liberar(&lista_principal);
    return 0;
}
