// Alterando uma estrutura
#include <stdio.h>

struct funcionario
{
    int idade;
    float salario;
    int horas;
};

int main(){
    struct funcionario f1;
    struct funcionario f2;
    struct funcionario f3;
    printf("Informe os dados dos funcionários: \n");
    scanf("%d %f %d", &f1.idade, &f1.salario, &f1.horas);
    scanf("%d %f %d", &f2.idade, &f2.salario, &f2.horas);
    scanf("%d %f %d", &f3.idade, &f3.salario, &f3.horas);

    // Para alterar o valor do salário
    f1.salario = f1.salario * 2;
    f2.salario = f2.salario * 2;
    f3.salario = f3.salario * 2;
    return 0;
}