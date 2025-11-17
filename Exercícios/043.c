#include <stdio.h>

typedef struct 
{
    char nome[50];
    int vida;
    int ataque;
}inimigo;


int main(){
    FILE *file = fopen("../wave_data.txt", "r");
    if (file == NULL){
        printf("Erro: nao foi possivel abrir o arquivo wave_data.txt\n");
        return 1;
    }
    inimigo i;
    inimigo mais_forte;
    int primeiro = 1;
    while (fscanf(file, "%s %d %d", i.nome, &i.vida, &i.ataque) != EOF){
        if (primeiro) {
            mais_forte = i;
            primeiro = 0;
        }

        if (i.ataque > mais_forte.ataque){
            mais_forte = i;
        }
    }
    fclose(file);
    printf("Maior ameaca: %s, Vida: %d, Ataque: %d", mais_forte.nome, mais_forte.vida, mais_forte.ataque);
    return 0;
}