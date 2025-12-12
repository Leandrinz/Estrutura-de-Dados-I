#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(Fila *f, Jogador j) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void mostrar(Fila *f) {
    No *aux = f->inicio;

    if (aux == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }

    while (aux != NULL) {
        printf("ID: %d | Nickname: %s\n", aux->dado.id, aux->dado.nickname);
        aux = aux->prox;
    }
}

Jogador remover(Fila *f) {
    Jogador vazio;
    vazio.id = -1;

    if (f->inicio == NULL) {
        printf("A fila esta vazia, nenhum jogador para remover.\n");
        return vazio;
    }

    No *rem = f->inicio;
    Jogador j = rem->dado;
    f->inicio = rem->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(rem);
    return j;
}

int estaVazia(Fila *f) {
    return f->inicio == NULL ? 1 : 0;
}

Jogador verInicio(Fila *f) {
    Jogador vazio;
    vazio.id = -1;

    if (f->inicio == NULL) {
        return vazio;
    }

    return f->inicio->dado;
}

void salvarFila(Fila *f, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para salvar a fila.\n");
        return;
    }

    No *aux = f->inicio;
    while (aux != NULL) {
        fwrite(&(aux->dado), sizeof(Jogador), 1, arq);
        aux = aux->prox;
    }

    fclose(arq);
    printf("Fila salva com sucesso em '%s'.\n", nomeArquivo);
}

void carregarFila(Fila *f, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) {
        printf("Nenhum arquivo encontrado. A fila sera inicializada vazia.\n");
        return;
    }

    Jogador j;
    while (fread(&j, sizeof(Jogador), 1, arq) == 1) {
        inserir(f, j);
    }

    fclose(arq);
    printf("Fila carregada com sucesso a partir de '%s'.\n", nomeArquivo);
}

int main() {
    Fila fila;
    inicializar(&fila);

    // Tenta carregar a fila do arquivo ao iniciar
    carregarFila(&fila, "matchmaking_queue.bin");

    int opc = -1;

    while (opc != 7) {
        printf("\n1. Adicionar Jogador na Fila\n");
        printf("2. Mostrar Fila\n");
        printf("3. Remover Jogador da Fila\n");
        printf("4. Verificar se a Fila esta Vazia\n");
        printf("5. Ver quem e o proximo da Fila\n");
        printf("6. Salvar Fila em Arquivo\n");
        printf("7. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Jogador j;
            printf("ID do jogador: ");
            scanf("%d", &j.id);
            printf("Nickname: ");
            scanf("%s", j.nickname);
            inserir(&fila, j);
        }

        else if (opc == 2) {
            mostrar(&fila);
        }

        else if (opc == 3) {
            Jogador r = remover(&fila);
            if (r.id != -1) {
                printf("O jogador %s (ID: %d) foi removido da fila.\n", r.nickname, r.id);
            }
        }

        else if (opc == 4) {
            if (estaVazia(&fila))
                printf("SIM, a fila esta vazia.\n");
            else
                printf("NAO, a fila contem jogadores.\n");
        }

        else if (opc == 5) {
            Jogador j = verInicio(&fila);
            if (j.id == -1) {
                printf("A fila esta vazia. Ninguem para consultar.\n");
            } else {
                printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
            }
        }

        else if (opc == 6) {
            salvarFila(&fila, "matchmaking_queue.bin");
        }
    }

    return 0;
}
