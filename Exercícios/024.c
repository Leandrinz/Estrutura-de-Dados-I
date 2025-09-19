#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas;
    printf("Digite o numero de linhas e colunas: \n");
    scanf("%d %d", &linhas, &colunas);
    int **mapa = malloc (linhas * sizeof(int *));
    for (int i = 0; i < 3; i++){
        mapa[i] = malloc (colunas * sizeof(int));
    }
    int l, c, numeros_tijolo = 0;
    printf("Digite 0, 1 ou 2: \n");
    for (l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            scanf("%d", &mapa[l][c]);
            if ((mapa[l][c]) == 1){
                numeros_tijolo += 1;
            }
        }
    }
    printf("O mapa possui %d blocos de tijolo.", numeros_tijolo);
    for (l = 0; l < linhas; l++){
        free(mapa[l]);
    }
    free(mapa);

    return 0;
}