#include <stdio.h>

struct jogador
{
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};


int main(){
    struct jogador heroi;
    
    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;
    
    if (heroi.tem_pulo_duplo == 0){
    printf("Início da fase! Posicao X: %f, Pontos: %d, Pulo Duplo: Sim \n", heroi.pos_x, heroi.pontuacao);
    }
    
    heroi.pontuacao += 10;
    heroi.tem_pulo_duplo = 1;

    if (heroi.tem_pulo_duplo == 1){
        printf("Itens coletados! Posicao X: %f, Pontos: %d, Pulo Duplo: Sim", heroi.pos_x, heroi.pontuacao);
    }

    return 0;
}