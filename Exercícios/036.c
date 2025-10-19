#include <stdio.h>
#include <stdlib.h>

struct moeda
{
    int posicao_x;
    int posicao_y;
    int valor;
};


int main(){
    int numero;
    
    printf("Quantas moedas você quer armazenar?\n");
    scanf("%d", &numero);
    
    struct moeda *v = (struct moeda*) malloc(numero * sizeof(struct moeda));
    
    for (int i = 0; i < numero; i++){
        scanf("%d %d %d", &v[i].posicao_x, &v[i].posicao_y, &v[i].valor);
    }

    int total_pontos = 0;

    for (int i = 0; i < numero; i++){
        total_pontos = total_pontos + v[i].valor;
    }

    printf("Pontuacao total do nivel: %d", total_pontos);

    free(v);

    return 0;
}