#include <stdio.h>

struct Monstro{
    int id;
    char nome[50];
    int hp;
    int ataque;
};

void ler(struct Monstro *pm){
    scanf("%d %s %d %d", &pm->id, pm->nome, &pm->hp, &pm->ataque);
}

void menu(){
    printf("===== Digite a opcao =====\n");
    printf("1 - Pesquisar \n");
    printf("0 - Sair\n");
    printf("==========================\n");
}

int buscaBinaria(int id, struct Monstro v[], int i, int f){
    if (i > f){
        return -1;
    }
    int meio = (i + f) / 2;
    if (v[meio].id == id){
        return meio;
    }
    if (v[meio].id < id){
        return buscaBinaria(id, v, meio + 1, f);
    }
    return buscaBinaria(id, v, i, meio -1);
}

int main(){
    int n;
    printf("Informe o total de monstros:\n");
    scanf("%d", &n);
    struct Monstro v[n];
    int i;
    for(i = 0; i < n; i++){
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while (op != 0){
        if (op == 1){
            int id;
            printf("Informe o ID:\n");
            scanf("%d", &id);
            int idx = buscaBinaria(id, v, 0, n-1);
            if (idx != -1){
                printf("Monstro Encontrado: %s\nId:%d\nHP:%d\nAtaque:%d\n", v[idx].nome, v[idx].id, v[idx].hp, v[idx].ataque);
            }
            if (idx == -1){
                printf("Monstro nao encontrado\n");
            }
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}