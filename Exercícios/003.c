#include <stdio.h>

int main(){
    float coordenada_x;
    float *ponteiro_x = &coordenada_x;
    printf("Digite a cordenada X do portal: ");
    scanf("%f", &coordenada_x);
    printf("Posicao do portal no eixo X: %.2f\n", *ponteiro_x);
    printf("Endereco do portal para o teletransporte: %p", ponteiro_x);
    return 0;
}