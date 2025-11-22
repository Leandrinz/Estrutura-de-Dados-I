#include <stdio.h>

void bolha(int n, int v[]){
    int i, j;
    for (i = 0; i < n - 1; i++){
        int trocou = 0;
        for (j = 0; j < n - i - 1; j++){
            if (v[j] < v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
        if (trocou == 1){
            return;
        }
    }
}

int main(){
    int n;
    printf("Informe a quantidade de jogadores:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    } 
    bolha(n, v);
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}