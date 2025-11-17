#include <stdio.h>


typedef struct 
{
    int resolucao_x;
    int resolucao_y;
    float volume_som;
}Configuracao;


int main(){
    FILE *file = fopen("../config.txt", "r");
    if (file == NULL){
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        exit(1);
    }
    int n;
    fscanf(file, "%d", &n);
    int i;
    for (i = 0; i < n; i++){
        Configuracao config;
        fscanf(file, "%d %d %f", &config.resolucao_x, &config.resolucao_y, &config.volume_som);
        printf("%d %d %.2f\n", config.resolucao_x, config.resolucao_y, config.volume_som);
    }
    fclose(file);
    return 0;
}