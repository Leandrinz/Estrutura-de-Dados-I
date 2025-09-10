// Vetor de strings

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    // Esse vetor recebe 3 strings, com cada uma podendo conter 49 caracteres + o /0

    char v[3][50];
    char s[50];

    printf("Informe as strigs:\n ");
    scanf("%s %s %s %s", v[0], v[1], v[2], s);

    int i;
    for (i = 0; i < 3; i++){
        if (strcmp(v[i], s) == 0){
            printf("%d\n", i);
        } 
    }



    return 0;
}