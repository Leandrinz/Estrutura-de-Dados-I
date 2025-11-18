#include <stdio.h>

typedef struct 
{
    char tipo[50];
    int HP;
}Inimigo;

int main(){
    Inimigo e;
    int i;
    int n;
    printf("Digite o valor de N: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%s %d", e.tipo, &e.HP);
        printf("Inimigo: %s, HP: %d\n", e.tipo, e.HP);
    }
    return 0;
}
