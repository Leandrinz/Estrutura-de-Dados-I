#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[50];
    int eliminacoes;
}Jogador;

void ler(Jogador *pj){
    scanf("%s %d", pj->nome, &pj->eliminacoes);
}

int main(){
    int n;
    printf("Digite o numero de jogadores:\n");
    scanf("%d", &n);
    int i, j;
    Jogador *v = calloc(n, sizeof(Jogador));
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    // Ordenação
    for (i = 0; i < n; i++){
        int imaior = i;
        for (j = i; j < n; j++){
            if (v[j].eliminacoes > v[imaior].eliminacoes){
                imaior = j;
            }
        }
        Jogador temp = v[i];
        v[i] = v[imaior];
        v[imaior] = temp;
    }
    for (i = 0; i < n; i++){
        printf("%s: %d\n", v[i].nome, v[i].eliminacoes);
    }
    return 0;
}