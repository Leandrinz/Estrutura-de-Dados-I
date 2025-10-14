// Acessando membros de um ponteiro para uma estrutura com a notação seta

#include <stdio.h>

struct pesquisa{
    int alcool;
    int gasolina;
    int diesel;
};


int main(){
    struct pesquisa p = {0,0,0};
    struct pesquisa *pp = &p;
    printf("Informe os votos dos clientes: \n");
    int voto;
    scanf("%d", &voto);
    while (voto != 4){
        if (voto == 1){
            pp->alcool++; // Invés de usar (*pp) usamos a seta que é pp->
        }
        else if(voto == 2){
            pp->gasolina++;
        }
        else{
            pp->diesel++;
        }
        scanf("%d", &voto);
    }
    printf("Alcool: %d\nGasolina: %d\nDiesel: %d", pp->alcool, pp->gasolina, pp->diesel);
    
    return 0;
}