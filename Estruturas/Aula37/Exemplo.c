// Aninhamento de Estruturas

#include <stdio.h> 

struct cliente
{
    int codigo;
    char nome[50]
};

struct comanda
{
    float total;
    struct cliente cli;
};


int main(){
    struct comanda c;
    printf("Informe os dados da comanda: \n");
    scanf("%f %d %s", &c.total, &c.cli.codigo, &c.cli.nome);
    float total = c.total - c.total * (5/100.0);
    printf("Total: %.2f", total);
}
