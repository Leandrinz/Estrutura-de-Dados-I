#include <stdio.h>
#include <string.h>
#include <locale.h>
#define AZUL "\x1B[4m"

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char palavra_secreta[50] = "LUX";
    char tentativa_jogador[50];
    printf("Diga a palavra passe...:   \n");
    scanf("%s", tentativa_jogador);
    if (strcmp(palavra_secreta, tentativa_jogador) == 0){
        printf("A porta mágica se abre!");
    }
    else{
        printf("Nada acontece... Parece que a palavra está incorreta.");
    }




    return 0;
}