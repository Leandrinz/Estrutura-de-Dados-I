#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char frase_inicio_luta[100] = "Voc� nunca sair� daqui com vida!";
    char caixa_dialogo[100] = "(Sil�ncio)";
    
    printf("%s\n", caixa_dialogo);
    
    strcpy(caixa_dialogo, frase_inicio_luta);
    
    printf("%s", caixa_dialogo);


    return 0;
}