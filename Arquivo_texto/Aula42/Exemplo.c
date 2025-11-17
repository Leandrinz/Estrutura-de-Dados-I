// Verificando se ocorreu erro ao abrir um arquivo
#include <stdio.h>


typedef struct 
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}estudante;


int main(){
    FILE *file = fopen("../estudantes.txt", "r");
    if (file == NULL){
        printf("Ocorreu um erro ao abrir o arquivo\n");
        system("pause");
        exit(1);
    }
    int n;
    fscanf(file, "%d", &n);
    int i;
    for (i = 0; i < n; i++){
        estudante e;
        fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
        if (e.nota1 >= e.nota2 && e.nota1 >= e.nota3){
            printf("%s:%.2f\n", e.nome, e.nota1);
        }
        else if (e.nota2 >= e.nota1 && e.nota2 >= e.nota3){
            printf("%s:%.2f\n", e.nome, e.nota2);
        }
        else{
            printf("%s:%.2f\n", e.nome, e.nota3);
        }
    }
    fclose(file);
    return 0;
}