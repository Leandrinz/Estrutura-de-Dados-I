#include <stdio.h>

typedef struct 
{
    int ID;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
}Personagem;

void ler(Personagem *pe){
    scanf("%d %s %d %d %d", &pe->ID, pe->nome, &pe->forca, &pe->agilidade, &pe->inteligencia);
}

void menu(){
    printf("====== Digite a opcao ======\n");
    printf("1 - Consultar personagem\n");
    printf("2 - Sair do programa\n");
    printf("============================\n");
}

int pesquisar(int ID, int total_personagens, Personagem v[]){
    int i;
    for (i = 0; i < total_personagens; i++){
        if (v[i].ID == ID){
            return i;
        }
    }
    return -1;
}

int main(){
    int total_personagens;
    printf("Informe o total de personagens:\n");
    scanf("%d", &total_personagens);
    int i;
    Personagem v[total_personagens];
    // Leitura e cadastramento dos personagens
    for (i = 0; i < total_personagens; i++){
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            int ID;
            printf("Informe o ID\n");
            scanf("%d", &ID);
            int idx = pesquisar(ID, total_personagens, v);
            if (idx != -1){
                float media_atributos = (v[idx].agilidade + v[idx].forca + v[idx].inteligencia) / 3.0;
                printf("%s:%.2f\n", v[idx].nome, media_atributos);
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}