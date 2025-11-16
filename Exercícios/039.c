#include <stdio.h>

typedef struct 
{
    char nome[50];
    float HP;
    float ATK;
}inimigo;


int main(){
    inimigo i1;
    inimigo i2;
    inimigo i3;
    inimigo v[3] = {i1, i2, i3};
    int i;
    FILE *file = fopen("../inimigos.txt", "r");
    for (i = 0; i < 3; i++){
        fscanf(file, "%s %f %f", v[i].nome, &v[i].HP, &v[i].ATK);
    }
    for (i = 0; i < 3; i++){
        float ameaca = v[i].ATK + v[i].HP;
        if (ameaca >= 200){
            printf("%s : %.2f\n", v[i].nome, ameaca);
        }
    }
    fclose(file);
    return 0;
}