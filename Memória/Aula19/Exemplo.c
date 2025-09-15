#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int *distancia = malloc(sizeof(int));
    float *litros = malloc(sizeof(float));
    float *consumo = malloc(sizeof(float));
    printf("Informe a distância percorrida e o total de litros gasto: \n");
    scanf("%d %f", distancia, litros);
    *consumo = *distancia / *litros;
    printf("%.2f km/l \n", *consumo);


    return 0;
}