// Verificicando o erro ao abrir um arquivo
#include <stdio.h>


int main(){
    FILE *file = fopen("naoexiste.b", "rb");
    if (file == NULL){
        printf("Ocorreu um erro ao abrir o arquivo");
        system("pause");
        perror(file); // Mostra qual foi o erro que ocorreu ao abrir o arquivo
        exit(1);
    }

    return 0;
}