#include <stdio.h>

typedef struct 
{
    char nome[50];
    int hp;
}Monstro;

void ler(Monstro *pm){
    scanf("%s %d", pm->nome, &pm->hp);
}

int main(){
    int n;
    printf("Digite o total de inimigos:\n");
    scanf("%d", &n);
    Monstro v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    Monstro menor_hp = v[0];
    for (i = 1; i < n; i++){
        if (v[i].hp < menor_hp.hp){
            menor_hp = v[i];
        }
    }
    printf("Alvo Prioritario: %s(HP:%d)", menor_hp.nome, menor_hp.hp);
    return 0;
}