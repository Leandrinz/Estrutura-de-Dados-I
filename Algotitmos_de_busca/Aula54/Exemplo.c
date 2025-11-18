// Algoritmos de busca - Busca linear
#include <stdio.h>

struct estudante{
    int mat;
    char nome[50];
    float n1;
    float n2;
    float n3;
};

void ler(struct estudante *pe){
    scanf("%d %s %f %f %f", &pe->mat, pe->nome, &pe->n1, &pe->n2, &pe->n3);
}

void menu(){
    printf("======= escolha uma opção =======\n");
    printf("1 - Pesquisar \n");
    printf("2 - Sair\n");
    printf("=================================");
}

int pesquisar(int mat, int n, struct estudante v[]){
    int i;
    for (int i = 0; i < n; i++){
        if (v[i].mat == mat){
            return i;
        }
    }
    return -1;
}


int main(){
    int n;
    printf("Informe o valor de n:\n");
    scanf("%d", &n);
    struct estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    int op;
    menu();
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            int mat;
            printf("Informe a matricula\n");
            scanf("%d", &mat);
            int idx = pesquisar(mat, n, v);
            if (idx != -1){
                float media = (v[idx].n1*2 + v[idx].n2*3 + v[idx].n3*4) / 9;
                printf("%s:%.2f", v[idx].nome, media);
            }
        }
        menu();
        scanf("%d", &op);
    }
    printf("Programa Finalizado!\n");
    return 0;
}