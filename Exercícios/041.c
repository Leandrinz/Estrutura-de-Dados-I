#include <stdio.h>
#include <stdlib.h>

void menu(){
    printf("======== digite a opcao ========\n");
    printf("1 - Nova frase\n");
    printf("2 - Sair do programa\n");
    printf("================================\n");
}


int main(){
    int op;
    menu();
    scanf("%d", &op);
    FILE *file = fopen("../game_log.txt", "a");
    while (op != 2){
        if (op == 1){
            char frase[50];
            scanf("%s", frase);
            fprintf(file, "%s", frase);
            fflush(file);
        }
        scanf("%d", &op);
    }
    fclose(file);
    return 0;
}
