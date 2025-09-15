#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int *vida_inimigo = malloc(sizeof(int)); // O operador sizeof em C serve para descobrir quantos bytes um tipo de dado ocupa na memória.
    if (vida_inimigo == NULL){
        printf("Erro!");
    }
    else{
        *vida_inimigo = 80;
        printf("Um novo inimigo apareceu com %d de vida!\n", *vida_inimigo);
        *vida_inimigo -= 35;
        printf("O jogador atacou! Vida restante do inimigo: %d", *vida_inimigo);
    }

    return 0;
}