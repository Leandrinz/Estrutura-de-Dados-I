// Vetores de ponteiros com aritm�tica de ponteiros
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    float e1[2];
    float e2[2];
    float e3[2];
    float *estudantes[3]; // Aqui criamos um vetor de ponteiros, onde armazenamos os valores dos 3 vetores
    estudantes[0] = e1;
    estudantes[1] = e2;
    estudantes[2] = e3;
    int i;
    for (i = 0; i < 3; i++){
        scanf("%f %f", (estudantes[i] + 0), (estudantes[i] + 1));
    }
    for (i = 0; i < 3; i++){
        if (*(estudantes[i] + 0) > *(estudantes[i] + 1)){
            printf("%.1f ", *(estudantes[i] + 0));
        }
        else{
            printf("%.1f ", *(estudantes[i] + 1));
        }
    }
    return 0;
}
//O vetor estudantes funciona como uma cole��o de ponteiros, cada ponteiro armazenando o endere�o de um vetor de notas.

// Gra�as a isso, voc� consegue acessar todas as notas como se tivesse uma matriz, mas usando ponteiros: estudantes[i][j].

// Essa t�cnica organiza melhor o c�digo sem precisar criar uma matriz 2D fixa.
// ex: (estudantes[i] + 0) - Pega o endere�o / *(estudantes [i][0] - Pega o conte�do)