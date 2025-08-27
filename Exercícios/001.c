#include <stdio.h>
#include <time.h>
// O Power-up e a Vida do Jogador
int main(){
    
    // Inicia vida do jogador e salva o endereço da variável no ponteiro
    int vida_jogador = 100;
    int *ponteiro_vida = &vida_jogador;
    
    // Simulando dano
    *ponteiro_vida = 50;
    printf("O jogador sofreu dano! Vida atual: %d\n", *ponteiro_vida);
    
    // Simulando Power-up
    *ponteiro_vida = 100;
    printf("Power-up coletado! Vida restaurada: %d", *ponteiro_vida);

    return 0;
}