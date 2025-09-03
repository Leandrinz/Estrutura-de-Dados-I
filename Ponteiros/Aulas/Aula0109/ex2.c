#include <stdio.h>

int main(){
    int i = 0;
    float v[6];
    int numeros_positivos = 0;
    float media = 0;
    float soma = 0;

    for (i = 0; i < 6; i++){
        scanf("%f", v + i);
        if (*(v + i) >= 0){
            numeros_positivos += 1;
            soma += *(v+i);
        }
    }
    media = soma / numeros_positivos;
    printf("%d valores positivos\n", numeros_positivos );
    printf("%.2f", media);

    return 0;
}