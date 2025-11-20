#include <stdio.h>

typedef struct 
{
    int ID;
    char nickname[50];
    int ponto_de_reputacao;
}Jogador;

void ler(Jogador *pj){
    scanf("%d %s %d", &pj->ID, pj->nickname, &pj->ponto_de_reputacao);
}

void menu(){
    printf("====== Digite a opcao ======\n");
    printf("1 - Digite a opcao\n");
    printf("2 - Sair\n");
    printf("============================\n");
}

int buscabinaria(int ID, int total_jogadores, Jogador v[]){
    int i = 0;
    int f = total_jogadores - 1;
    while (i <= f){
        int meio = (i + f) / 2;
        if (v[meio].ID == ID){
            return i;
        }
        else if (v[meio].ID < ID){
            i = meio + 1;
        }
        else{
            f = meio - 1;
        }
    }
    return -1;
    
}

int main(){
    int total_jogadores;
    printf("Digite o total de jogadores:\n");
    scanf("%d", &total_jogadores);
    Jogador v[total_jogadores];
    menu();
    int opcao;
    printf("Escolha a opcao:\n");
    scanf("%d", &opcao);
    while (opcao != 2){
        if (opcao == 1){
            int ID;
            printf("Digite o ID:\n");
            scanf("%d", &ID);
            int idx = buscabinaria(ID, total_jogadores, v);
            v[idx].ponto_de_reputacao += 100;
            printf("Nickname: %s, Nova Reputacao: %d\n", v[idx].nickname, v[idx].ponto_de_reputacao);
            if (idx == -1){
                printf("Jogador com ID %d nao encontrado!\n", ID);
            }
        }
        menu();
        printf("Escolha a opcao:\n");
        scanf("%d", &opcao);
    }
    printf("Programa finalizado!\n");
    return 0;
}