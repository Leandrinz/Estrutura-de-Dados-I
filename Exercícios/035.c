#include <stdio.h>

struct ItemColetavel
{
    char nome[50];
    int valor_pontos;
};



int main(){
    struct ItemColetavel inventario[3];
    for (int i = 0; i < 3; i++){
        printf("Nome do item %d:", i + 1);
        scanf("%s", inventario[i].nome);
        printf("Valor do item %d: ", i + 1);
        scanf("%d", &inventario[i].valor_pontos);
    }
    
    struct ItemColetavel maior = inventario[0];
    
    for (int i = 1; i < 3; i++){
        if (maior.valor_pontos < inventario[i].valor_pontos){
            maior = inventario[i];
        }
    }
    
    printf("O item coletado mais valioso foi: %s", maior.nome);

    return 0;
}