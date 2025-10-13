// Passando um ponteiro de um tipo struct para uma função

#include <stdio.h>

struct funcionario
{
    int matricula;
    float salario;
};


void aumento(struct funcionario *pf){
    (*pf).salario = (*pf).salario + (*pf).salario * (15.0/100.0);
}


int main(){
    struct funcionario f;
    struct funcionario *pf = &f;
    printf("Informe os dados do funcionario: \n");
    scanf("%d %f", &(*pf).matricula, &(*pf).salario);
    // Usamos &(*pf) para pegarmos o endereço do ponteiro 
    aumento(pf);
    printf("Apos o aumento, o salario do funcionario eh de: %.2f", (*pf).salario);
    return 0;
}