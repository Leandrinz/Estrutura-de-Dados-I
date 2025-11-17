// Escrevendo um vetor para um arquivo
#include <stdio.h>

typedef struct 
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}estudante;

int main(){
    FILE *file = fopen("../estudantes.b", "wb");
    int n;
    printf("Informe a quantidade de estudantes: \n");
    scanf("%d", &n);
    estudante v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%s %f %f %f", v[i].nome, &v[i].nota1, &v[i].nota2, &v[i].nota3);
    }
    fwrite(v, sizeof(estudante), n, file);
    for (i = 0; i < n; i++){
        if (v[i].nota1 >= v[i].nota2 && v[i].nota1 >= v[i].nota3){
            printf("%s:%.2f\n",v[i].nome, v[i].nota1);
        }
        else if (v[i].nota2 >= v[i].nota1 && v[i].nota2 >= v[i].nota3){
            printf("%s:%.2f\n", v[i].nome, v[i].nota2);
        }
        else{
            printf("%s:%.2f\n", v[i].nome, v[i].nota3);
        }
    }
    fclose(file);
    return 0;
}