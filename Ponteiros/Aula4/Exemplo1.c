#include <stdio.h>

void dobro( int *pn){
    *pn = *pn * 2;
    printf("Valor de a na funcao: %d\n", *pn);

}


int main(){
    int n;
    int *pn = &n;
    printf("Digite um valor: ");
    scanf("%d", pn);
    dobro(pn);
    printf("Valor de a na main: %d", n);

    return 0;
}