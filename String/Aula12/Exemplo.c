// Tamanho de Uma String

#include <stdio.h>
#include <locale.h>
#include <string.h> // Para sabermos o tamanho de uma string precisamos importar essa biblioteca.


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char s[500];
    
    printf("Informe o texto para ser verificado: ");
    scanf("%[^\n]s", s); 
    // Se colocamos %s para ler strings, ele vai ler apenas a primeira palavra.

    // Então, para ler tudo, teremos que colocar ("%[^\n]s")

    // Note que no scanf nn colocamos um & pq a string já é um endereço de memória.

    printf("%s\n", s);

    if (strlen(s) > 80){
        printf("Não!");
    }
    else{
        printf("SIM!");
    }




    return 0;
}