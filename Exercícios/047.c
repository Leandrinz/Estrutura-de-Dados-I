#include <stdio.h>

typedef struct 
{
    char nome[50];
    int vida;
    int ataque;
}Unidade;

int main(){
    int n;
    printf("Digite o valor de n:\n");
    scanf("%d", &n);
    Unidade v[n];
    FILE *file = fopen("../squad_dat.b", "wb");
    int i;
    for (i = 0; i < n; i++){
        scanf("%s %d %d", v[i].nome, &v[i].vida, &v[i].ataque);
    }
    Unidade maior = v[0];
    for (i = 1; i < n; i++){
        if (v[i].ataque > maior.ataque){
            maior = v[i];
        }
    }
    printf("%s:%d", maior.nome, maior.ataque);
    fwrite(v, sizeof(Unidade), n, file);
    fclose(file);
    return 0;
}