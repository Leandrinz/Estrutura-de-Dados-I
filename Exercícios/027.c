#include <stdio.h>

struct inimigo
{
    int vida;
    int ataque;
    float velocidade;
};



int main(){
    struct inimigo cogumelo_zumbi;
    struct inimigo cavaleiro_esqueleto;
    
    cogumelo_zumbi.vida = 20;
    cogumelo_zumbi.ataque = 5;
    cogumelo_zumbi.velocidade = 0.8;
    
    cavaleiro_esqueleto.vida = 80;
    cavaleiro_esqueleto.ataque = 15;
    cavaleiro_esqueleto.velocidade = 1.2;

    printf("--- Atributos do Inimigo: Cogumelo Zumbi ---\n");
    printf("Vida: %d \nAtaque: %d \nVelocidade: %f", cogumelo_zumbi.vida, cogumelo_zumbi.ataque, cogumelo_zumbi.velocidade);
    printf("\n \n");
    printf("--- Atributos do Inimigo: Cavaleiro Esqueleto ---\n");
    printf("Vida: %d \nAtaque: %d \nVelocidade: %f", cavaleiro_esqueleto.vida, cavaleiro_esqueleto.ataque, cavaleiro_esqueleto.velocidade);

    return 0;
}