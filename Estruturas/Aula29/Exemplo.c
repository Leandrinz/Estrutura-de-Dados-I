// Inicializando uma estrutura
#include <stdio.h>


struct produto
{
    int codigo;
    float preco;
};


int main(){
    struct produto p1 = {1, 2.50}; // O número 1, ficou armazenado em p1.codigo, e 2.50 em p1.preco
    struct produto p2 = {2, 4.00};
    struct produto p3 = {3, 5.00};
    int quantidade;
    int codigo;
    printf("Informe a quantidade e o codigo do produto: \n");
    scanf("%d %d", &quantidade, &codigo);
    if (codigo == p1.codigo){
        float valor = p1.preco * quantidade;
        printf("%.2f", valor);
    }
    else if (codigo == p2.codigo)
    {
        float valor = p2.preco * quantidade;
        printf("%.2f", valor); 
    }
    else{
        float valor = p3.preco * quantidade;
        printf("%.2f", valor); 
    }
    
}