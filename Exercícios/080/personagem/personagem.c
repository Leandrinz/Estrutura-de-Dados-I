#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[30];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    Personagem* party = (Personagem*) malloc(num_membros * sizeof(Personagem));
    return party;
}

void registra_membros(Personagem* party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("=== Membro %d ===\n", i + 1);
        printf("Nome: ");
        scanf("%49s", party[i].nome);

        printf("Classe: ");
        scanf("%29s", party[i].classe);

        printf("Nivel: ");
        scanf("%d", &party[i].nivel);

        printf("HP: ");
        scanf("%d", &party[i].hp);

        printf("\n");
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    printf("\n===== RELATORIO DA EQUIPE =====\n");

    for (int i = 0; i < num_membros; i++) {
        printf("Membro %d:\n", i + 1);
        printf("Nome: %s\n", party[i].nome);
        printf("Classe: %s\n", party[i].classe);
        printf("Nivel: %d\n", party[i].nivel);
        printf("HP: %d\n", party[i].hp);
        printf("-----------------------------\n");
    }
}

void libera_party(Personagem* party) {
    free(party);
}
