#include <stdio.h>

int main(){
    int fase[10] = {0,1,0,0,1,1,0,1,0,0};
    int *ponteiro_jogador = fase;
    int moedas_coletadas = 0;
    int c;
    for (c = 0; c < 10; c++){
        if (*(ponteiro_jogador + c) == 1){
            moedas_coletadas += 1;
        }   
    }
    printf("O jogador coletou um total de %d moedas!", moedas_coletadas);

    return 0;
}