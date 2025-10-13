#include <stdio.h>

struct Posicao{
    int x;
    int y;
};

void mover_personagem(struct Posicao *ponteiro_posicao, int movimento_x, int movimento_y){
    (*ponteiro_posicao).x += movimento_x;
    (*ponteiro_posicao).y += movimento_y;
}



int main(){
    struct Posicao posicao_jogador;
    posicao_jogador.x = posicao_jogador.y = 0;
    struct Posicao *ponteiro_posicao = &posicao_jogador;
    printf("Posicao incial do jogador: X = %d, Y = %d\n", (*ponteiro_posicao).x, (*ponteiro_posicao).y);
    mover_personagem(ponteiro_posicao, 10, 5);
    printf("Posicao final do jogador: X = %d, Y = %d", (*ponteiro_posicao).x, (*ponteiro_posicao).y);
    return 0;
}