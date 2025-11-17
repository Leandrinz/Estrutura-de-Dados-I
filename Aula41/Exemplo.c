// Adicionando dados ao fim de um arquivo de texto
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
}estudante;


void menu(){
    printf("======== digite a opçao ========");
    printf("1 - cadastrar novo aluno\n");
    printf("2 - sair\n");
    printf("================================");
}


int main(){
    FILE *file = fopen("../estudantes.txt", "a");
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            estudante e;
            scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
            fprintf(file, "%s %f %f %f\n", e.nome, &e.nota1, &e.nota2, &e.nota3);
            fflush(file); // força a escrita
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado\n");
    fclose(file);

    return 0;
}