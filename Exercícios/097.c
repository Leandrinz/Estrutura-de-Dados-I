#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Membro {
    int id;
    char nome[50];
    struct Membro *prox;
} Membro;

typedef Membro* Lista;

void adicionar_membro(Lista *lista) {
    Membro *novo = (Membro*) malloc(sizeof(Membro));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o ID: ");
    scanf("%d", &novo->id);
    getchar();

    printf("Digite o nome: ");
    fgets(novo->nome, 50, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Membro *aux = *lista;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    printf("Membro adicionado!\n");
}

void mostrar_lista(Lista lista) {
    if (lista == NULL) {
        printf("A guilda está vazia!\n");
        return;
    }

    printf("\n===== LISTA DA GUILDA =====\n");

    Membro *aux = lista;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->id, aux->nome);
        aux = aux->prox;
    }

    printf("===========================\n");
}

void salvar_guild_arquivo(Lista lista) {
    FILE *file = fopen("guild_roster.bin", "wb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Membro *aux = lista;

    while (aux != NULL) {
        fwrite(&(aux->id), sizeof(int), 1, file);
        fwrite(aux->nome, sizeof(char), 50, file);
        aux = aux->prox;
    }

    fclose(file);
    printf("Arquivo 'guild_roster.bin' salvo com sucesso!\n");
}

int main() {
    Lista guilda = NULL;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar membro\n");
        printf("2 - Mostrar guilda\n");
        printf("3 - Salvar guilda no arquivo\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_membro(&guilda);
                break;
            case 2:
                mostrar_lista(guilda);
                break;
            case 3:
                salvar_guild_arquivo(guilda);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}
