#include <stdio.h>
#include "combate.h"

int main(){
    int ataque_base_heroi, bonus_espada, vida_total;
    printf("Informe a vida do heroi, bonus de ataque da espada, e vida total:\n");
    scanf("%d %d %d", &ataque_base_heroi, &bonus_espada, &vida_total);
    int dano = calcular_ataque_total(ataque_base_heroi, bonus_espada);
    int vida_pos_ataque = aplicar_dano(vida_total, dano);
    printf("Vida total:%d\nAtaque do heroi + Bonus de sua espada:%d\nVida do inimigo pos ataque:%d\n", vida_total, dano, vida_pos_ataque);
    return 0;
}