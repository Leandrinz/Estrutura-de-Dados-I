#include <stdio.h>

int main(){
    int r, i = 0;
    int posicao = 0;
    int *pr = &r;
    int men = 0;
    int *pmen = &men;


    scanf("%d", pr);

    int v[*pr];

    for (i = 0; i < *pr; i++){
        scanf("%d", &v[i]);
        if (i == 0){
            *pmen = v[i];
        }
        if (v[i] <*pmen){
            *pmen = v[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", *pmen);
    printf("Posicao: %d", posicao);
    return 0;
}