#include <stdio.h>

int main(){
    int v[5] = {120, 125, 130, 142, 150};
    int novo_tempo;
    printf("Digite o novo tempo:\n");
    scanf("%d", &novo_tempo);
    int i;
    if (novo_tempo < v[4]){
        for (i = 4; i >= 0 && novo_tempo < v[i]; i--){
            if (i < 4){
                v[i + 1] = v[i];
            }
        }
        v[i + 1] = novo_tempo;
    }
    for (i = 0; i < 5; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}