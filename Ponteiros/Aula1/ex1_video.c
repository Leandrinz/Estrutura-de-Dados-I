#include <stdio.h>

int main(){
    int a, b, x;
    int *pa, *pb, *px;
    pa = &a;
    pb = &b;
    printf("Digite o valor de A e B: ");
    scanf("%d %d", pa, pb );
    x = a + b;
    printf("A soma de %d + %d eh: %d", a, b, x);
    return 0;
}