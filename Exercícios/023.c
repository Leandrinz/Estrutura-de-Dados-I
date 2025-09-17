#include <stdio.h>
#include <stdlib.h>

#define LINHAS  5
#define COLUNAS 10

int main(){ 
    int *level_map = (int *) malloc(LINHAS * COLUNAS * sizeof(int));
    if (level_map == NULL){
        printf("Erro!");
    }
    int i, j;
    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){

            if (i == LINHAS - 1){
                *(level_map + i * COLUNAS + j) = 1;
            }
            else{
                *(level_map + i * COLUNAS + j) = 0;
            }
        }
    }
    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            printf("%d", *(level_map + (i * COLUNAS) + j));
        }
        printf("\n");
    }
    free(level_map);

    return 0;
}