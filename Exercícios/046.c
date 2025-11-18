#include <stdio.h>

typedef struct 
{
    char nome[50];
    int nivel;
    int highScore;
}PlayerProfile;


int main(){
    FILE *file = fopen("../profiles.dat.b", "rb");
    PlayerProfile e;
    while (fread(&e, sizeof(PlayerProfile), 1, file)){
        if (e.highScore >= 10000){
            printf("%s: Mestre do Jogo\n", e.nome);
        }
        else if (e.highScore > 5000 && e.highScore < 10000){
            printf("%s: Veterano\n", e.nome);
        }
        else {
            printf("%s: Aspirante\n", e.nome);
        }
    }
    printf("Programa finalizado!");
    fclose(file);
    return 0;
}