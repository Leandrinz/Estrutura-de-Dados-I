// Quicksort - com estruturas
#include <stdio.h>

typedef struct 
{
    int mat;
    char nome[50];
}estudante;

int particiona(int e, int d, estudante v[]){
    estudante pivo = v[d];
    int j = -1;
    int i;
    for (i = e; i < d; i++){
        if (v[i].mat <= pivo.mat){
            j++;
            estudante temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    estudante temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;
    return j + 1;
}

void quicksort(int i, int f, estudante v[]){
    if (i < f){
        int p = particiona(i, f, v);
        quicksort(i, p - 1, v);
        quicksort(p + 1, f, v);
    }
}

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    quicksort(0, n-1, v);
    for (i = 0; i < n; i++){
        printf("%s:%d\n", v[i].nome, v[i].mat);
    }
    return 0;
}