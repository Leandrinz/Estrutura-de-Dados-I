#include <stdio.h>

int main(){
    int a, b, c, d;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    int *pd = &d;
    printf("Digite os valores de a, b, c, d: \n");
    scanf("%d %d %d %d", pa, pb, pc, pd);
    int DIFERENCA = ((*pa * *pb) - (*pc * *pd));
    // Quando se adiciona o *, estamos acessando o conteúdo do endereço.
    int *pdif = &DIFERENCA;
    printf("DIFERENCA: %d", *pdif);


    return 0;
}