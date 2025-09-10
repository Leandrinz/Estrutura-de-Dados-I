#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char nome_jogador[50];
    char titulo_conquistado[50];
    
    printf("Digite o nome do herói: ");
    scanf("%s", nome_jogador);
    
    printf("Digite o título conquistado: ");
    scanf("%s", titulo_conquistado);

    strcat(nome_jogador, " ");

    strcat(nome_jogador, titulo_conquistado);

    printf("O herói agora é conhecido como: %s", nome_jogador);


    return 0;
}