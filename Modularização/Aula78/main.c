#include <stdio.h>
#include "calculadora.h"

int main(){
    int a, b;
    printf("Informe os valores de a e b:\n");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, adiciona(a,b));
    printf("%d - %d = %d\n", a, b, subtrai(a, b));
    printf("%d * %d = %d\n", a, b, multiplica(a, b));
    printf("%d / %d = %d\n", a, b, divide(a, b));
    return 0;
}