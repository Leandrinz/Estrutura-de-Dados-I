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
    
    // Agora queremos que a vari�vel s2 receba uma c�pia do mesmo conte�do da vari�vel s1
    
    // Para isso fazemos uso de uma fun��o chamada: strcpy

    strcpy(s2, s1);
    // Traduzindo: Pegue a vari�vel s2 e coloque nela uma c�pia da vari�vel s1

    printf("%s", s2);
    
    return 0;
}