#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    char inventario[5][20];
    printf("Digite o nome dos 5 itens do seu inventário: ");
    scanf("%s %s %s %s %s", inventario[0], inventario[1], inventario[2], inventario[3], inventario[4]);
    char item_necessario[19];
    printf("Digite o nome do item para abrir a porta: ");
    scanf("%s", item_necessario);
    
    int i;
    for (i = 0; i < 5; i++){
        if (strcmp(inventario[i], item_necessario) == 0){
            break;
        }
    }
    
    if  (strcmp(inventario[i], item_necessario) == 0){
        printf("Porta aberta!");
    }   
    else{
        printf("Você não tem o item necessário.");
    }
    
    return 0;
}