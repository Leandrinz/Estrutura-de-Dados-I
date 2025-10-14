// Vetor de estruturas
#include <stdio.h>


struct cliente
{
    char nome[50];
    float saldo;
};




int main(){
    struct cliente v[3];
    printf("Informe os dados dos clientes: \n");
    int i;
    for (i = 0; i < 3; i++){
        scanf("%s %f", v[i].nome, &v[i].saldo);
    }
    struct cliente maior = v[0];
    for (i = 1; i < 3; i++){
        if (v[i].saldo > maior.saldo){
            maior = v[i];
        }
    }
    printf("%s possui o maior saldo\n", maior.nome);

    return 0;
}