// Vetores de Ponteiros
#include <stdio.h>

int main(){
    
    // e1, e2, e3 são ponteiros
    float e1[2], e2[2], e3[2];
    
    // Para criar um vetor que armazena 3 ponteiros para float:
    float *estudantes[3];

    estudantes[0] = e1;
    estudantes[1] = e2;
    estudantes[2] = e3;

    int i;

    for (i = 0; i < 3; i++){
        scanf("%f %f", &estudantes[i][0], &estudantes[i][1]);
    }

    for ( i = 0; i < 3; i++){
        float media = (estudantes[i][0] + estudantes[i][1])/2;
        printf("%.2f ", media);
    }
    

    return 0;
}