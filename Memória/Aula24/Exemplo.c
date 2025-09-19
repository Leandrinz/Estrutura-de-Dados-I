#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    int **m = malloc(3 *  sizeof(int *)); // Fazendo um int **m você cria um ponteiro inteiro para ponteiro
    // Para o malloc pegar um ponteiro inteiro, fazemos sizeof(int *)
    printf("Informe os valores: \n"); 
    for (i = 0; i < 3; i++){
        m[i] = (int *) malloc(2 * sizeof(int));
    }
   
    for (i = 0; i < 3; i++){
         for (j = 0; j < 2; j++){
            scanf("%d", &m[i][j]);
        }
    }
    int pares = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            if (m[i][j] % 2 == 0){
                pares += 1;
            }
        }
    }
    for (i = 0; i < 3; i++){
        free(m[i]);
    }
    free(m);

    printf("Pares: %d", pares);
    return 0;
}