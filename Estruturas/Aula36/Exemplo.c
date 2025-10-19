// Alocação dinâmica de estruturas
#include <stdio.h>
#include <stdlib.h>

struct item
{
    int quantidade;
    float preco;
};

int main(){
    struct item *v = (struct item*) malloc(3 * sizeof(struct item));
    printf("Informe os dados do pedido: \n");
    int i;
    for (i = 0; i < 3; i++){
        scanf("%d %f",&v[i].quantidade, &v[i].preco);
    }
    float total = 0;
    for (i = 0; i < 3; i++){
        total = total + v[i].quantidade * v[i].preco;
    }
    printf("Total: %.2f", total);
    return 0;
}