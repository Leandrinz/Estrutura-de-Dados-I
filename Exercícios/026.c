#include <stdio.h>
#include <stdlib.h>

int main(){
    int *mochila = (int *) malloc(3 * sizeof(int));
    
    printf("Digite o valor dos 3 itens encontrados: \n");
    
    for (int i = 0; i < 3; i++){
        scanf("%d", &mochila[i]);
    }

    mochila = (int *) realloc(mochila, 3 * 2 * sizeof(int));

    printf("Digite os valores dos 3 novos itens: \n");

    for (int i = 3; i < 2 * 3; i++){
        scanf("%d", &mochila[i]);
    }

    for (int i = 0; i < 6; i++){
        printf("%d ", mochila[i]);
    }
    free(mochila);

    return 0;
}