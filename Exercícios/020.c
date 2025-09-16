#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    void *ponteiro_duracao = malloc(sizeof(int));
    *((int *) ponteiro_duracao) = 10;
    printf("Power-up 'Super Salto' ativado! Dura??o: %d segundos.\n", *((int *) ponteiro_duracao));
    *((int *) ponteiro_duracao) -= 3;
    printf("3 segundos se passaram... Dura??o restante: %d segundos.", *((int *) ponteiro_duracao));
    free(ponteiro_duracao);

    return 0;
}