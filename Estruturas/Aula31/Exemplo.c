// Utilizando typedef para definir uma estrutura
#include <stdio.h>

typedef struct
{
    float nota1;
    float nota2;
    float nota3;
}estudante; // Com o typedef, colocamos o nome da estrutura aqui em baixo, no caso estudantes



int main(){
    estudante e; // Com isso, agora só chamamos o nome da estrutura e pronto
    printf("Informe as notas do estudante: \n");
    scanf("%f %f %f", &e.nota1, &e.nota2, &e.nota3);
    float media = (e.nota1 + e.nota2 + e.nota3) / 3 ;
    printf("%.2f", media);
}