#include <stdio.h>

typedef struct 
{
    char nome[50];
    int pontuacao;
}jogador;

void ler(jogador *pj){
    scanf("%s %d", pj->nome, &pj->pontuacao);
}

int main(){
    int n;
    printf("Informe o numero de jogadores:\n");
    scanf("%d", &n);
    jogador v[n];
    int i, j;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    for (i = 0; i < n; i++){
        jogador x = v[i];
        for (j = i - 1; j >=0 && x.pontuacao > v[j].pontuacao; j--){
            v[j + 1] = v[j];  
        }
        v[j + 1] = x;
    }
    for (i = 0; i < n; i++){
        printf("%s:%d\n", v[i].nome, v[i].pontuacao);
    }
    return 0;
}