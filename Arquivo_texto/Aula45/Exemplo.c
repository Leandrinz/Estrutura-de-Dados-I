// Escrevendo para um arquivo binário
#include <stdio.h>

typedef struct 
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}estudante;

void menu(){
    printf("====== escolha uma opcao ====== \n");
    printf("1 - cadastrar novo estudante\n");
    printf("2 - sair\n");
    printf("===============================\n");
}


int main(){
    FILE *file = fopen("../estudantes.b", "wb"); // wb significa que o arquivo deve ser tratado como um arquivo binário
    menu();
    int op;
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            printf("Informe os dados do estudante\n");
            estudante e;
            scanf("%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
            fwrite(&e, sizeof(estudante), 1, file); // usamos fwrite para escrever em arquivo de bits. parâmetros(o que vai ser passado, tamanho, quantidade, e onde será armazenado)
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!");
    fclose(file);

    return 0;
}