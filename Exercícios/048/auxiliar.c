#include <stdio.h>

typedef struct 
{
    char nome[50];
    int vida;
    int ataque;
}Campeao;

int main(){
    Campeao c;
    FILE *file = fopen("../squad.dat", "wb");
    int i;
    for (i = 0; i < 3; i++){
        printf("Informe os dados do campeao: \n");
        scanf("%s %d %d", c.nome, &c.vida, &c.ataque);
        fwrite(&c, sizeof(Campeao), 1, file);
    }
    fclose(file);
    return 0;
}