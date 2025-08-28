#include <stdio.h>

void aplicar_powerup_pontuacao_dupla(int *ppj){
    *ppj = *ppj * 2;
}


int main(){
    int pontuacao_jogador = 1500;
    int *ppj = &pontuacao_jogador;
    printf("Pontuacao antes do Power-up: %d\n", *ppj);
    aplicar_powerup_pontuacao_dupla(ppj);
    printf("Pontuacao apos o Power-up: %d", *ppj);
    return 0;
}