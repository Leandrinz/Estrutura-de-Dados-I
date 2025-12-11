#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    int nivel;
} Membro;

typedef struct No {
    Membro dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;


void inicializar_lista(Lista *l) {
    l->inicio = NULL;
}


void inserir_final(Lista *l, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}


void mostrar_guilda(Lista l) {
    if (l.inicio == NULL) {
        printf("A guilda está vazia!\n");
        return;
    }

    No *aux = l.inicio;
    printf("\n=== MEMBROS DA GUILDA ===\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s | Nivel: %d\n",
               aux->dado.id,
               aux->dado.nome,
               aux->dado.nivel);
        aux = aux->prox;
    }
    printf("=========================\n");
}


void salvar_guilda_teste() {
    FILE *f = fopen("guild_roster.b", "wb");
    if (f == NULL) {
        printf("Erro ao criar arquivo de teste.\n");
        return;
    }

    Membro m1 = {1, "Alduin", 50};
    Membro m2 = {2, "Serana", 35};
    Membro m3 = {3, "Kodlak", 60};

    fwrite(&m1, sizeof(Membro), 1, f);
    fwrite(&m2, sizeof(Membro), 1, f);
    fwrite(&m3, sizeof(Membro), 1, f);

    fclose(f);
    printf("Arquivo guild_roster.b criado com 3 membros!\n");
}


Lista carregar_guilda() {
    Lista lista;
    inicializar_lista(&lista);

    FILE *f = fopen("guild_roster.b", "rb");
    if (f == NULL) {
        printf("Erro ao abrir guild_roster.b para leitura.\n");
        return lista; 
    }

    Membro temp;

    while (fread(&temp, sizeof(Membro), 1, f) == 1) {
        inserir_final(&lista, temp);
    }

    fclose(f);

    printf("Guilda carregada com sucesso!\n");
    return lista;
}


int main() {
    salvar_guilda_teste();

    Lista guilda = carregar_guilda();

    mostrar_guilda(guilda);

    return 0;
}
