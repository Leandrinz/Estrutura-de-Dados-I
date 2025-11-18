#include <stdio.h>

int main(){ 
    FILE *file = fopen("level_1_map.dat", "r");
    if (file == NULL){
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa!\n");
        system("pause");
        perror(file);
        exit(1);
    }

    return 0;
}