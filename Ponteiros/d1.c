#include <stdio.h>
 
int main() {
    // Valores aceitos: B > C, D > A, CD > AB, C e D > 0, A % 2 == 0.
    int A, B, C, D;
    int *pa = &A;
    int *pb = &B;
    int *pc = &C;
    int *pd = &D;
    printf("Digite o valor de A, B, C, D: ");
    scanf("%d %d %d %d", pa, pb, pc, pd);
    int CD = *pc + *pd;
    int AB = *pa + *pd;
    if (*pb > *pc && *pd > *pa && (*pc + *pd)  > (*pa + *pb) && *pc > 0 && *pd > 0 && *pa % 2 == 0){
        printf("Valores Aceitos");
    } 
    else{
        printf("Valores nao aceitos");
    }
    return 0;
}