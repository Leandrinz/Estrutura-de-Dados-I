// Lendo de um arquivo binário
#include <stdio.h>

typedef struct 
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}estudante;


int main(){
    FILE *file = fopen("../estudantes.b", "rb");
    estudante e;
    while (fread(&e, sizeof(estudante), 1, file)){ // fread : Para continuar lendo enquanto a função conseguir ler com sucesso o número de elementos solicitado (neste caso, 1).
        float media = (e.nota1 + e.nota2 + e.nota3) / 3;
        if (media >= 7.0){
            printf("%s: Aprovado", e.nome);
        }
        else if (media < 5.0){
            printf("%s: reprovado", e.nome);
        }
        else{
            float precisa = 10.0 - media;
            printf("%s: Final - %.2f", e.nome, precisa);
        }
    }
    printf("Programa finalizado!");
    fclose(file);
    return 0;
}