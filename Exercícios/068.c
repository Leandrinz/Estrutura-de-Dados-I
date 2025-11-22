#include <stdio.h>

typedef struct 
{
    int id;
    int pontuacao;
}jogador;

bolha(int n, jogador v[]){
    int i, j;
    for (i = 0; i < n - 1; i++){
        int trocou = 0;
        for (j = 0; j < n - i - 1; j++){
            if (v[j].pontuacao < v[j + 1].pontuacao){
                jogador temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou == 0){
            return;
        }
    }
}

void ler(jogador *pj){
    scanf("%d %d", &pj->id, &pj->pontuacao);
}

int main(){
    int n;
    printf("Informe o numero de jogadores:\n");
    scanf("%d", &n);
    int i;
    jogador v[n];
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    bolha(n, v);
    for (i = 0; i < n; i++){
        printf("%d:%d\n", v[i].id, v[i].pontuacao);
    }
    return 0;
}