#include <stdio.h>

typedef struct 
{
    char nome[50];
    int vida;
    int ataque;
}Campeao;

int main(){
    FILE *file = fopen("../squad.dat", "rb");
    Campeao c[3];
    fread(&c, sizeof(Campeao), 3, file);
    int i;
    Campeao maior_vida = c[0];
    for (i = 1; i < 3; i++){
        if (c[i].vida > maior_vida.vida){
            maior_vida = c[i];
        }
    }
    printf("Tanque do esquadrão: %s: %d Vida", maior_vida.nome, maior_vida.vida);
    fclose(file);
    return 0;
}
