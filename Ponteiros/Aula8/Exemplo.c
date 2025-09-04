// Imprimindo vetor em uma função usando aritmética de ponteiros
#include <stdio.h>

void imprime(int n, int v[]){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
}


int main(){
    int n;
    int *pn = &n;
    
    // Digita o total de valores a ser lido
    printf("Digite a quantidade de valores que serao lidos: \n");
    scanf("%d", pn);
    
    int v[n];
    int i;
    
    // Preenche o vetor
    for (i = 0; i < n; i++){
        scanf("%d", v + i);
    }
    
    // Dobra os valores do vetor 
    for (i = 0; i < n; i++){
        *(v + i) *= 2;
    }
    
    // Chama a função para imprimir o vetor na tela, já com os valores atualizados! 
    imprime(n,v);
    
    return 0;
}