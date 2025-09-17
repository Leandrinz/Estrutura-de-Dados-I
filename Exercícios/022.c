#include <stdio.h>
#include <stdlib.h>


int main(){
    int n_inimigos;
    printf("Digite o total de inimigos: \n");
    scanf("%d", &n_inimigos);
    int *ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));
    int contador;
    for (contador = 0; contador < n_inimigos; contador++){
        scanf("%d", &ponteiro_onda[contador]);
    }
    printf("Onda de inimigos criada com sucesso! IDS: ");
    for (contador = 0; contador < n_inimigos; contador++){
        printf("%d ", ponteiro_onda[contador]);
    }

    return 0;
}