#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float *ponteiro_altura_salto_duplo = NULL;
    printf("Jogador ainda n�o possui o Salto Duplo.\n");
    ponteiro_altura_salto_duplo = malloc(sizeof(float));
    if (ponteiro_altura_salto_duplo != NULL){
        
        *ponteiro_altura_salto_duplo = 15,5;
        
        printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f", *ponteiro_altura_salto_duplo);

    }
    free(ponteiro_altura_salto_duplo); // Libera��o de mem�ria ap�s o uso do power-up

    return 0;
}