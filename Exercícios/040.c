#include <stdio.h>

typedef struct
{
    char nome[50];
    int pontuacao;
}jogador;


int main(){
    int n;
    printf("Digite N:\n");
    scanf("%d", &n);
    jogador v[n];
    FILE *file = fopen("../highscore.txt", "w");
    int i;
    for (i = 0; i < n; i++){
        scanf("%s %d", v[i].nome, &v[i].pontuacao);
    }
    jogador maior = v[0];
    for (i = 1; i < n; i++){
        if (v[i].pontuacao > maior.pontuacao){
            maior = v[i];
        }
    }
    fprintf(file, "%s: %d", maior.nome, maior.pontuacao);
    fclose(file);
    return 0;
}