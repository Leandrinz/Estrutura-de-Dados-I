// Passando uma estrutura para uma função
#include <stdio.h>


 struct jogo
{
    int vasco;
    int flamengo;
};


void analisa(struct jogo g);


int main(){
    struct jogo g;
    printf("Informe a quantidade de gols do Vasco e Flamengo: \n");
    scanf("%d %d", &g.vasco, &g.flamengo);
    analisa(g);
    



    return 0;
}


void analisa(struct jogo g){
    if (g.vasco > g.flamengo){
        printf("O Vasco venceu");
    }
    else if (g.flamengo == g.vasco)
    {
        printf("Empate");
    }
    else{
        printf("Roubando, o flamengo vence o vasco no sufoco.");
    }
}