#include <stdio.h>

int main(){
    int n;
    printf("Digite o valor de N:\n");
    scanf("%d", &n);
    int v[n];
    int i, j;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++){
        int imenor = v[i];
        for (j = i; j < n; j++){
            if (v[j] < v[imenor]){
                imenor = j;
            }
        }
        int temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp; 
    }
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}