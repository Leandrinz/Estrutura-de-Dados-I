// Enum
#include <stdio.h>

enum tipo {VIP, NORMAL};

struct comanda
{
    float total;
    char nome[50];
    enum tipo cliente;
};


int main(){
    struct comanda c;
    printf("Informe os dados da comanda: \n");
    scanf("%f %s %d", &c.total, &c.nome, &c.cliente);

    if (c.cliente == VIP){
        float total = c.total - c.total * (20/100.0);
        printf("%.2f\n", total);
    }
    else if(c.cliente == NORMAL){
        float total = c.total - c.total * (5/100.0);
        printf("%.2f", total);
    }
    else{
        printf("%.2f", c.total);
    }


    return 0;
}
