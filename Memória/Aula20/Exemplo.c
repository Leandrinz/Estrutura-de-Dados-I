// Alocação de Memória - Ponteiro genérico //

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    void *n = malloc(sizeof(int)); // O void pode apontar para qualquer tipo de ponteiro
    int positivos = 0; 
    
    printf("Digite o valor de n: ");
    scanf("%d", (int *) n); // Aqui convertemos o ponteiro que podeeria ser qualquer um, para inteiro.
    
    for (int c = 0; c < *((int *) n); c++){ // o (int *) converte o ponteiro para um ponteiro inteiro
        void *numero = malloc(sizeof(float));
        scanf("%d", (float *) numero);
        if ((*(float *) numero) > 0){
            positivos += 1;
        }
    }
    
    printf("%d", positivos);

    return 0;
}