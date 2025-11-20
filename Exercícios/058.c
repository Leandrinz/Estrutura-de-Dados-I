#include <stdio.h>

int calcularDanoEco(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
}

int main(){
    int n;
    printf("Informe o numero do golpe na sequencia ecoante do Golpe ecoante:\n");
    scanf("%d", &n);
    int dano = calcularDanoEco(n);
    printf("Dano do bonus resultante:%d\n", dano);
    return 0;
}