#include <stdio.h>

int main(){
    float a, b, media;
    float *pa = &a;
    float *pb = &b;
    float *pmed = &media;
    
    // Recebe valor de A e B
    printf("Digite a nota A, e em seguida a nota B: ");
    scanf("%f %f", pa, pb);
    
    // Calcula média
    *pmed = ((*pa * 3.5) + (*pb * 7.5)) / 11; 
    printf("Media: %.2f\n", *pmed);
    printf("Endereco da media: %p", pmed);
    return 0;
}