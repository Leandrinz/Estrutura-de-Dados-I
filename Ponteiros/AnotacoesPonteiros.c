#include <stdio.h>



int main(){
    //!showMemory(start=65520)
    // Se quiser que vire ponteiro é so fazer *pa, coloque um asterisco antes da variável:
    int a = 2, b = 3, s;
    int soma;
    int *pa = &a;
    int *pb = &b;
    int *ps = &s;
    soma = *pa + *pb;
    // Aqui a soma está pegando o valor de pa e pb, e não o endereço e soma.
    // Exemplo: *pb é o endereço da variável b, e &b é o endereço. Por isso que *pb agora vira endereço. 
    // O endereço vai ser onde ele começa.
    printf("Vasco\n");
    printf("A soma de a mais b eh %d", soma);
    return 0;
}