#include <stdio.h>

int max_div_conq(int v[], int inicio, int fim){
    // Caso base: apenas um elemento
    if (inicio == fim){
        return v[inicio];
    }

    int meio = (inicio + fim) / 2;

    // Conquistar: achar máximo da metade esquerda e direita
    int max_esq = max_div_conq(v, inicio, meio);
    int max_dir = max_div_conq(v, meio + 1, fim);

    // Combinar: retorna o maior entre eles
    return (max_esq > max_dir) ? max_esq : max_dir;
}

int main(){
    int n;
    printf("Informe a quantidade de Fragmentos da alma:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int maior = max_div_conq(v, 0, n - 1);

    printf("%d\n", maior);

    return 0;
}