#include <stdio.h>

struct Personagem
{
    int posX;
    int posY;
    int moedas;
};


struct Personagem atualizarPersonagem(struct Personagem jogador);


int main(){
    struct Personagem jogador;

    jogador.posX = 0;
    jogador.posY = 0;
    jogador.moedas = 0;

    printf("Posicao Inicial: (%d, %d) - Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);
    jogador = atualizarPersonagem(jogador);
    printf("Posicao atualizada: (%d, %d) - Moedas: %d", jogador.posX, jogador.posY, jogador.moedas);

    return 0;
}


struct Personagem atualizarPersonagem(struct Personagem jogador){
    jogador.moedas = 1;
    jogador.posX = 10;
    jogador.posY = 5;   
    return jogador;
} 