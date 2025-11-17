// Lendo e escrevendo para um arquivo
#include <stdio.h>

typedef struct 
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}estudante;


int main(){
    FILE *file = fopen("../estudantes.txt", "r+"); // r+ ele faz leitura e escrit caso o arquivo já existir
    int n;
    fscanf(file, "%d", &n);
    int i;
    estudante e;
    for (i = 0; i < n; i++){
        fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
        int cont = 0;
        if (e.nota1 == 10){
            cont++;
        }
        if (e.nota2 == 10){
            cont++;
        }
        if (e.nota3 == 10){
            cont++;
        }
        printf("%s:%d\n", e.nome, cont);
    }
    fseek(file, 0, SEEK_CUR); // Para limpar o indicador de fim de arquivo (EOF) e alternar o modo interno do fluxo de dados de leitura para escrita.
    fprintf(file, "\nPrograma finalizado." );
    fclose(file);
    return 0;
}