#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monstro {
    int id;               // Nível de ameaça
    char nome[50];
    struct Monstro *prox;
} Monstro;

// Função para adicionar monstro no final da lista
void adicionarMonstro(Monstro **inicio) {
    Monstro *novo = (Monstro*) malloc(sizeof(Monstro));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o nivel de ameaca (ID): ");
    scanf("%d", &novo->id);

    printf("Digite o nome do monstro: ");
    getchar(); 
    fgets(novo->nome, 50, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; // Remover quebra de linha

    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        Monstro *aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Monstro adicionado com sucesso!\n");
}

// Função para mostrar a lista
void mostrarBestiario(Monstro *inicio) {
    if (inicio == NULL) {
        printf("O bestiario esta vazio!\n");
        return;
    }

    Monstro *aux = inicio;
    printf("\n===== BESTIARIO =====\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->id, aux->nome);
        aux = aux->prox;
    }
    printf("=====================\n");
}

// Função Bubble Sort na lista encadeada
void ordenarBestiario(Monstro *inicio) {
    if (inicio == NULL) {
        printf("O bestiario esta vazio, nada para ordenar.\n");
        return;
    }

    int trocou;
    Monstro *atual;
    Monstro *ultimo = NULL;

    do {
        trocou = 0;
        atual = inicio;

        while (atual->prox != ultimo) {
            if (atual->id > atual->prox->id) {
                // Trocar os dados (id e nome) entre os nós
                int tempId = atual->id;
                atual->id = atual->prox->id;
                atual->prox->id = tempId;

                char tempNome[50];
                strcpy(tempNome, atual->nome);
                strcpy(atual->nome, atual->prox->nome);
                strcpy(atual->prox->nome, tempNome);

                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while (trocou);

    printf("Bestiario ordenado com sucesso!\n");
}

int main() {
    Monstro *inicio = NULL;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar monstro\n");
        printf("2 - Ordenar bestiario\n");
        printf("3 - Mostrar bestiario\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarMonstro(&inicio);
                break;
            case 2:
                ordenarBestiario(inicio);
                break;
            case 3:
                mostrarBestiario(inicio);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
