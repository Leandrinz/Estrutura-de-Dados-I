#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char nome_jogador[50];
    printf("Digite o seu nome: ");
    scanf("%[^\n]s", nome_jogador);
    if (strlen(nome_jogador) > 15){
        printf("%s � Muito longo, Escolha outro nome com at� 15 caracteres!", nome_jogador);
    }
    else{
        printf("Nome v�lido! Bem-vindo ao jogo, %s!", nome_jogador);
    }




    return 0;
}