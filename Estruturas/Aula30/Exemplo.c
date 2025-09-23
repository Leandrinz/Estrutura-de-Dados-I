// Modificando um membro do tipo string de uma estrutura
#include <stdio.h>
#include <string.h>


struct funcionario
{
    int matricula;
    char nome[50];
    int horas;
    float valorhora
};


int main(){
    struct funcionario f;
    char nome[50];
    printf("Informe os dados do funcionario: \n");
    scanf("%d %s %d %f", &f.matricula, &nome, &f.horas, &f.valorhora);
    strcpy(f.nome, nome); // Fazemos essa copia por que de alguma forma o scanf nn suporta colocar diretamente lá no struct, então em caso de char, faça a copia com uma variável auxiliar
    float salario = f.horas * f.valorhora;
    printf("Salario de %s: %.2f", f.nome, salario);
    return 0;
}