#include <stdio.h>

void particao(int n, int v[]){
    int s[n];
    int e = 0;
    int d = n - 1;
    int pivo = v[n - 1];
    int i;
    for (i = 0; i < n; i++){
        if (v[i] < pivo){
            s[e] = v[i];
            e++;
        }
        else{
            s[d] = v[i];
            d--;
        }
    }
    for (i = 0; i < n; i++){
        v[i] = s[i];
    }
}

int main(){
    int n;
    printf("Informe a quantidade de itens:\n");
    scanf("%d", &n);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    particao(n, v);
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}