// Unindo duas strings - strcat //

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char s1[50];
    char s2[50];
    printf("Informe duas strings: ");
    scanf("%s %s", s1, s2);

    // Para juntar duas strings fazemos: 
    strcat(s1, s2);

    // O conte�do de s2 � adicionado ao final de s1, e o resultado final � armazenado na vari�vel s1.
    
    printf("%s", s1);
    
    return 0;
}