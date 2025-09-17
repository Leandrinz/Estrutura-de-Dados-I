// Alocação de memória - matrizes com único ponteiro
#include <stdio.h>
#include <stdlib.h>


int main(){
    int *m = (int *) malloc( 3 * 2 * sizeof(int)); // Pra alocar no malloc uma matriz, só fazemos (linhas * colunas * sizeof(int))
    printf("Informe os valores: \n");
    int i, j, positivos = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", m + (i * 2) + j);   // acessa a posição equivalente a m[i][j] na forma linear.
                                            // (i * 2) desloca 'i' linhas completas (cada linha tem 2 colunas),
                                            // e depois soma 'j' para chegar na coluna correta.
                                            // Ou seja: posição = i * número_de_colunas + j.
            if (*(m + (i * 2) + j) > 0){
                positivos++;
            }
        }
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            printf("%d   ", *(m + (i * 2) + j));
            
        }
        printf("\n");
    }
    printf("Positivos: %d", positivos);


    return 0;
}