#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "");

    // O QUE ACONTECE NO FREE: A mem?ria é marcada como disponível para o sistema, mas o ponteiro pa continua guardando o mesmo endere?o de antes. Acessar esse endere?o é considerado um comportamento indefinido.

    
    int pares = 0;
    printf("Informe o valor de a: \n");
    int *pa = (int *) malloc(sizeof(int));
    scanf("%d", pa);
    if (*pa % 2 == 0){
        pares++;
    }
    free(pa);
    
    printf("Informe o valor de b: \n");
    int *pb = (int *) malloc(sizeof(int));
    scanf("%d", pb);
    if (*pb % 2 == 0){
        pares++;
    }
    free(pb);
    
    printf("Informe o valor de c: \n");
    int *pc = (int *) malloc(sizeof(int));
    scanf("%d", pc);
    if (*pc % 2 == 0){
        pares++;
    }
    free(pc);
    

    printf("Pares: %d", pares);

    free(pa);
    free(pb);
    free(pc);

    return 0;
}