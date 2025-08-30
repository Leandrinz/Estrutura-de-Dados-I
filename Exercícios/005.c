#include <stdio.h>

int main(){
    int pontuacao = 0, c;
    int *ponteiro_pontuacao = &pontuacao;
    printf("Pontuacao inicial : %d\n", *ponteiro_pontuacao);
    for (c = 0; c < 3; c++){
        *ponteiro_pontuacao += 10;
    }
    printf("Pontuacao final apos coletar 3 moedas : %d", *ponteiro_pontuacao);

    return 0;
}