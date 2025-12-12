// historico.c

#include "historico.h"

// ----------------------------------------------------------------
// FUNÇÕES AUXILIARES
// ----------------------------------------------------------------

int comparar_scores(const void *a, const void *b) {
    Score *scoreA = (Score *)a;
    Score *scoreB = (Score *)b;

    if (scoreA->tempo < scoreB->tempo) return 1;    // Tempo B é maior (deve vir primeiro, pois tempo menor = score maior)
    if (scoreA->tempo > scoreB->tempo) return -1;   // Tempo A é maior (deve vir primeiro)
    return 0; // Tempos iguais
}

int buscar_jogador_linear(const Score *scores, int num_scores, const char *nome_alvo) {
    for (int i = 0; i < num_scores; i++) {
        if (strcmp(scores[i].nome, nome_alvo) == 0) {
            return i; 
        }
    }
    return -1;
}

// ----------------------------------------------------------------
// FUNÇÃO PRINCIPAL DE SCORE
// ----------------------------------------------------------------

void salvar_e_ordenar_historico(const char *novo_nome, double novo_tempo) {
    // ESTA É A IMPLEMENTAÇÃO COMPLETA
    Score scores[1000]; 
    int num_scores = 0;
    
    // --- 1. LEITURA DOS SCORES EXISTENTES ---
    FILE *leitura_file = fopen("historico.txt", "r");
    
    if (leitura_file != NULL) {
        while (fscanf(leitura_file, "%49[^:]:%lf\n", scores[num_scores].nome, &scores[num_scores].tempo) == 2) {
             num_scores++;
             if (num_scores >= 1000) break; 
        }
        fclose(leitura_file);
    } 

    // --- 2. ATUALIZAÇÃO DO NOVO SCORE ---
    int indice_existente = buscar_jogador_linear(scores, num_scores, novo_nome);
    
    if (indice_existente != -1) {
        // Jogador existe: Checa se o novo tempo é um recorde
        if (novo_tempo > scores[indice_existente].tempo) {
            scores[indice_existente].tempo = novo_tempo;
            printf("Score de %s atualizado para %.2f\n", novo_nome, novo_tempo);
        } else {
            printf("Score de %s nao e um novo recorde. Mantendo o score anterior.\n", novo_nome);
            return; // Sai da função sem reescrever o arquivo, pois não houve mudança.
        }
        
    } else {
        // Jogador novo: Adiciona no final do array (se houver espaço)
        if (num_scores < 1000) {
            strcpy(scores[num_scores].nome, novo_nome);
            scores[num_scores].tempo = novo_tempo;
            num_scores++; 
        }
    }
    
    // --- 3. ORDENAÇÃO E ESCRITA NO ARQUIVO ---
    
    // Ordena o array completo de scores (existentes + novo)
    qsort(scores, num_scores, sizeof(Score), comparar_scores);
    
    FILE *escrita_file = fopen("historico.txt", "w"); // Abre para escrita (sobrescreve)

    if (escrita_file != NULL) {
        for (int i = 0; i < num_scores; i++) {
            // Escreve o score no formato NOME:TEMPO\n
            fprintf(escrita_file, "%s:%.2f\n", scores[i].nome, scores[i].tempo);
        }
        fclose(escrita_file);
        printf("Histórico de scores atualizado e ordenado.\n");
    } else {
        fprintf(stderr, "Erro fatal: Nao foi possivel reescrever o arquivo historico.txt.\n");
    }
}