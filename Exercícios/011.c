#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2]= {2, 2};
    
    // Cria um vetor de ponteiro 
    int *inventarios[3];
    
    // Conecta o vetor para as variáveis criadas
    inventarios[0] = balas;
    inventarios[1] = granadas;
    inventarios[2] = foguetes;
    
    // Printa o início do inventário
    printf("Inventário Inicial: \n Balas: %d\n Granadas: %d\n Foguetes: %d \n", *(inventarios[0] + 0), *(inventarios[1] + 0), *(inventarios[2] + 0));
    
    int i;
    // Diminui uma unidade do inventário
    for (i = 0; i < 3; i++){
        *(inventarios[i] + 0) -= 1;
    }
    
    printf("Inventário após uso: \n Balas: %d\n Granadas: %d\n Foguetes: %d \n", *(inventarios[0] + 0), *(inventarios[1] + 0), *(inventarios[2] + 0));
    
    return 0;
}