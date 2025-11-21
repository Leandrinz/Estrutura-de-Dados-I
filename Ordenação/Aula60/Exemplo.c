// Selecionar o menor elemento de um vetor
#include <stdio.h>

typedef struct 
{
    int mat;
    char nome[50];

}Estudante;

void ler(Estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}

int main(){
    int n;
    printf("Digite o valor de N:\n");
    scanf("%d", &n);
    Estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    Estudante menor = v[0];
    for (i = 1; i < n; i++){
        if (v[i].mat < menor.mat){
            menor = v[i];
        }
    }
    printf("%s:%d", menor.nome, menor.mat);
    return 0;
}