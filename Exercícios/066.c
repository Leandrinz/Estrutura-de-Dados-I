#include <stdio.h>

int main(){ 
    int n;
    printf("Digite o numero de jogadores:\n");
    scanf("%d", &n);
    int i, j;
    int v[n];
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (v[j] < v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}