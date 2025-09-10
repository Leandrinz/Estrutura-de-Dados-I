// Copiando uma String //
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char s1[50];
    char s2[50];
    printf("Informe uma string a ser copiada: ");
    scanf("%s", s1);
    
    // Agora queremos que a variável s2 receba uma cópia do mesmo conteúdo da variável s1
    
    // Para isso fazemos uso de uma função chamada: strcpy

    strcpy(s2, s1);
    // Traduzindo: Pegue a variável s2 e coloque nela uma cópia da variável s1

    printf("%s", s2);
    
    return 0;
}