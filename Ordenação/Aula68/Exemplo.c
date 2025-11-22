// Ordenação por trocas sucessivas de estruturas
#include <stdio.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

void bolha(int n, estudante v[]){
    int i, j;
    for (i = 0; i < n - 1; i++){
        int trocou = 0;
        for (j = 0; j < n - i - 1; j++){
            if (v[j].mat > v[j + 1].mat){
                estudante temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou = 0){
            return;
        }
    }
}

int main(){
    int n;
    printf("Informe o numero de estudantes:\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    bolha(n, v);
    for (i = 0; i < n; i++){
        printf("%s:%d\n", v[i].nome, v[i].mat);
    }
    return 0;
}