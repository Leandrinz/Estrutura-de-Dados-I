#include <stdio.h>

int main(){ 
    int moedas_coletadas[5] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    for (int *ponteiro_moeda = moedas_coletadas;
            ponteiro_moeda < moedas_coletadas + 5;
            ponteiro_moeda++) {
        pontuacao_total += *ponteiro_moeda;
    }
    printf("Pontuacao total do nivel: %d", pontuacao_total);


    return 0;
}