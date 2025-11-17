// Verificar se arquivo chegou ao fim
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
    estudante e;
    // pra que isso? Ele permite processar todas as linhas do arquivo sem precisar saber previamente quantas linhas existem.
    while (fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3) != EOF){ // Verifica enquanto nao chega ao fim
        float media = (e.nota1 + e.nota2 + e.nota3) / 3;
        printf("%s:%.2f\n", e.nome, media);
    }
    fclose(file);
    return 0;
}