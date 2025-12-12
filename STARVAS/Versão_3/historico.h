// historico.h

#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para o Score
typedef struct {
    char nome[50];
    double tempo;
} Score;

// Protótipos das Funções
int comparar_scores(const void *a, const void *b);
int buscar_jogador_linear(const Score *scores, int num_scores, const char *nome_alvo);
void salvar_e_ordenar_historico(const char *novo_nome, double novo_tempo);

#endif // HISTORICO_H