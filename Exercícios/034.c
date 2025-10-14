#include <stdio.h>

struct Heroi
{
    int saude;
    int pontuacao;
    int posX;
    int posY;
};



int main(){
    struct Heroi meuHeroi;
    meuHeroi.saude = 100;
    meuHeroi.pontuacao = 0;
    meuHeroi.posX = 0;
    meuHeroi.posY = 0;
   
   
    printf("Saude: %d\nPontuacao: %d\nPosX: %d\nPosY: %d\n \n", meuHeroi.saude, meuHeroi.pontuacao, meuHeroi.posX, meuHeroi.posY);
    struct Heroi *ptrHeroi = &meuHeroi;
   
    ptrHeroi->saude -= 25;
    ptrHeroi->pontuacao += 50;
    ptrHeroi->posX += 10;
    ptrHeroi->posY -= 5;
   
    printf("Saude: %d\nPontuacao: %d\nPosX: %d\nPosY: %d", ptrHeroi->saude, ptrHeroi->pontuacao, ptrHeroi->posX, ptrHeroi->posY);



    return 0;
}

