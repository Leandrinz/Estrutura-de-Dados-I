// Ordenação por seleção
#include <stdio.h>

int main(){
    int n;
    printf("Digite o valor de n:\n");
    scanf("%d", &n);
    int v[n];
    int i, j;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    // Ordenação por seleção
    for (i = 0; i < n; i++){
        int imenor = i;
        for (j = i + 1; j < n; j++){
            if (v[j] < v[imenor]){
                imenor = j;
            }
        }
        int temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp;
    }
    printf("Lista ordenada:\n");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}