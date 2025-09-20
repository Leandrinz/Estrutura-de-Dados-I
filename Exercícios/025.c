#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero_inimigos;
    
    printf("Digite a quantidade de inimigos: \n");
    scanf("%d", &numero_inimigos);
    
    int *status_inimigos = (int *) calloc(numero_inimigos, sizeof(int));
    
    for (int contador = 0; contador < numero_inimigos; contador++){
        printf("Inimigo %d: Inativo (%d)", contador, status_inimigos[contador]);
        printf("\n");
    }

    for (int contador = 0; contador < numero_inimigos; contador++){
        
        status_inimigos[contador] = 1; 

    }
    
    printf("\n");

    for (int contador = 0; contador < numero_inimigos; contador++){
        printf("Inimigo %d: Ativo (%d)", contador, status_inimigos[contador]);
        printf("\n");
    }

    free(status_inimigos);

    return 0;
}