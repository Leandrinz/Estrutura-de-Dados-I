#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int mapa_fase1[5][8] = {{0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0},  {1, 1, 0, 0, 2, 0, 1, 1},  {0, 0, 1, 1, 0, 1, 0, 0},  {1, 1, 1, 1, 2, 2, 1, 1}};
    int coluna, linha;

    // Exibixão do mapa
    for (linha = 0; linha < 5; linha++){
        for (coluna = 0; coluna < 8; coluna++){
            if (mapa_fase1[linha][coluna] == 0){
                printf(". ");
            }
            else if(mapa_fase1[linha][coluna] == 1){
                printf("# ");
            }
            else if(mapa_fase1[linha][coluna] == 2){
                printf("^ ");
            }
        }
        printf("\n");
    }


    for (linha = 0; linha < 5; linha++){
        for (coluna = 0; coluna < 8; coluna++){
            if (mapa_fase1[linha][coluna] == 2){
                printf("Espinho encontrado na linha %d, coluna %d. \n", linha + 1, coluna + 1);
            }
        }
    }
    return 0;
}