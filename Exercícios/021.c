#include <stdio.h>
#include <stdlib.h>



int main(){
    int *duracao_fumaca = (int *) malloc(sizeof(int));
    if (duracao_fumaca == NULL){
        printf("Erro");
    }
    *duracao_fumaca = 5;
    printf("Bomba de fumaca atividade! Duracao: %d segundos.\n", *duracao_fumaca);
    free(duracao_fumaca);
    duracao_fumaca = NULL;
    printf("A fumaca se dissipou!");
    return 0;
}