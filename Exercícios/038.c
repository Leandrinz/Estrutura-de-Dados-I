#include <stdio.h>

enum EstadoPersonagem {PARADO, CORRENDO, PULANDO};


int main(){
    enum EstadoPersonagem estado_atual;
    
    printf("Digite o estado em que o personagem se encontra: \n");
    scanf("%d", &estado_atual);
    
    if (estado_atual == PARADO){
        printf("O personagem esta parado!");
    }
    else if (estado_atual == CORRENDO)
    {
        printf("O personagem esta correndo!");
    }
    else if (estado_atual == PULANDO)
    {
        printf("O personagem esta pulando no ar!");
    }
    else{
        printf("Estado Invalido!");
    }
    
    return 0;
}
