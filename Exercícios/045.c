#include <stdio.h>


typedef struct 
{
    char nome[50];
    int nivel;
    float vida;
    float mana;
}Personagem;

void menu(){
    printf("========== digite a opcao ==========\n");
    printf("1 - Criar novo personagem\n");
    printf("2 - Sair do Programa\n");
    printf("====================================\n");
}


int main(){
    FILE *file = fopen("../savegame_sab.b", "wb");
    menu();
    int op;
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            printf("Informe os dados do persongaem:\n");
            Personagem boneco;
            scanf("%s %d %f %f", boneco.nome, &boneco.nivel, &boneco.vida, &boneco.mana);
            fwrite(&boneco, sizeof(Personagem), 1, file);
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!");
    fclose(file);
    return 0;
}