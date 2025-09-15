// Alocação de Memória - Malloc //
#include <stdio.h>
#include <locale.h>
// Pra usar essa função, devemos importar a biblioteca a seguir: 
#include <stdlib.h>


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *phoras = (int *) malloc(4); // Aqui, o malloc ele reserva a quantidade de bytes que desejamos, como é um inteiro, colocamos 4 dentro do parênteses
    // E o (int *) serve para converter o armazenamento do malloc para um inteiro de ponteiro.

    
    float *pvhora = (float *) malloc(8); // Como agora é um float, devemos reservar 8 bytes.

    float *psalario = (float *) malloc(8);
    
    printf("Informe quantas horas trabalhou e o valor de cada hora: \n");
    
    scanf("%d %f", phoras, pvhora);
    
    *psalario = *phoras * *pvhora;
    
    printf("%.2f", *psalario);




    return 0;
}