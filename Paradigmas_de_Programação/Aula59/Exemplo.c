#include <stdio.h>

struct estudante
{
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
    printf("======== Escolha a opcao ========\n");
    printf("1 - Pesquisar\n");
    printf("2 - Sair\n");
    printf("=================================\n");
}

int buscaBinaria(int mat, struct estudante v[], int i, int f){
    if (i > f){
        return -1;
    }
    int meio = (i + f) / 2;
    if (v[meio].mat == mat){
        return meio;
    }
    if (v[meio].mat < mat){
        return buscaBinaria(mat, v, meio + 1, f);
    }
    return buscaBinaria(mat, v, i, meio - 1);
}

int main(){
    int n;
    printf("Informe a quantidade de estudantes:\n");
    scanf("%d", &n);
    int i;
    struct estudante v[n];
    for (i = 0; i < n; i++){
        ler(&v[i]);
    }
    menu();
    int op;
    scanf("%d", &op);
    while (op != 2){
        if (op == 1){
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            int idx = buscaBinaria(mat, v, 0, n-1);
            if (idx != -1){
                v[idx].n3 = v[idx].n3 + 1;
                float media = (v[idx].n1*2 + v[idx].n2*3 + v[idx].n3*4) / 9;
                printf("Nome: %s, Media:%.2f\n", v[idx].nome, media);
            }
            if (idx == -1){
                printf("Aluno nao encontrado!\n");
            }
        }

        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado!\n");
    return 0;
}