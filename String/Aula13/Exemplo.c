// Comparando duas strings - strcmp
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char s1[50];
    char s2[50];
    printf("Informe as duas Strings: \n");
    scanf("%s %s", s1, s2);
    if (strcmp(s1, s2) == 0){
        printf("Iguais!");
    }
    else{
        printf("Diferentes!");
    }
    
    // Se o strcmp retorna:
        // 0 - As palavras são idênticas
        //-1 - Se s1 vier primeiro que s2 na ordem alfabética
        // 1 - Se s2 vier primeiro que s2 na ordem alfabética


    return 0;
}