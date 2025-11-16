// Lendo um arquivo de texto //

#include <stdio.h>

typedef struct
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} estudante;


int main(){
    estudante e1;
    estudante e2;
    estudante e3;
    estudante v[3] = {e1, e2, e3};
    int i;
    // Aqui o diferencial, criamos um ponteiro que aponta pro nosso arquivo e vai abrir ele e pegar
    // as informações que queremos
    FILE *file = fopen("../estudantes.txt", "r"); // funciona só se o arquivo de texto estiver na mesma pasta/ "r" serve pra ler o arquivo. USE .. ANTES DO /
    printf("Digite os nomes e as 3 notas dos 3 estudantes:\n");
    for (i = 0; i < 3; i++){
        // Como lidamos com arquivo, usamos o fscanf
        fscanf(file, "%s %f %f %f", v[i].nome, &v[i].nota1, &v[i].nota2, &v[i].nota3);
    }
    for (i = 0; i < 3; i++){
        float media = (v[i].nota1 + v[i].nota2 + v[i].nota3) / 3;
        if (media >= 7.0){
            printf("%s: %.2f\n", v[i].nome, media);
        }
    }
    fclose(file);

    return 0;
}
