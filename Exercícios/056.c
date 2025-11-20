#include <stdio.h>

int calculo_dano(nivel_mago){
    if (nivel_mago == 1){
        return 1;
    }
    return nivel_mago + calculo_dano(nivel_mago - 1);
}

int main(){
    int nivel_mago;
    printf("Informe o nivel do mago:\n");
    scanf("%d", &nivel_mago);
    int dano_mago = calculo_dano(nivel_mago);
    printf("O dano do mago no nivel %d eh de: %d", nivel_mago, dano_mago);
    return 0;
}