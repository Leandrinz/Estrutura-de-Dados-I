// Ordenação por seleção de estruturas
#include <stdio.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    estudante v[n];
    int i, j;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    // Ordenação de seleção
    for (i = 0; i < n; i++){
        int imenor = i;
        for (j = i; j < n; j++){
            if (v[j].mat < v[imenor].mat){
                imenor = j;
            }
        }
        estudante temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp;
    }
    for (i = 0; i < n; i++){
        printf("%d: %s\n", v[i].mat, v[i].nome);
    }


    return 0;
}