// Introdução as estruturas
#include <stdio.h>

struct funcionario
{
    int idade;
    float salario;
    int horas;
};


int main(){

// Usando vetores para separar não é a melhor escolha, pois os dados ficam separados, por isso usamos estruturas.
    struct funcionario f[3];
    printf("Informe os dados dos funcionários: \n");
    int i;
    for (i = 0; i < 3; i++){
        scanf("%d %f %d", &f[i].idade, &f[i].salario, &f[i].horas);
    }
    int imaior = 0;
    for (i = 1; i < 3; i++){
        if (f[i].salario > f[imaior].salario){
            imaior = i;
        }
    }
    printf("Maior salario: %d", imaior + 1);
    return 0;
}