#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char nome_jogador[50];
    char titulo_conquistado[50];
    
    printf("Digite o nome do her�i: ");
    scanf("%s", nome_jogador);
    
    printf("Digite o t�tulo conquistado: ");
    scanf("%s", titulo_conquistado);

    strcat(nome_jogador, " ");

    strcat(nome_jogador, titulo_conquistado);

    printf("O her�i agora � conhecido como: %s", nome_jogador);


    return 0;
}