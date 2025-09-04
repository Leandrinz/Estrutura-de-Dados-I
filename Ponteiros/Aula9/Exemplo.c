// Incremento de Ponteiros
#include <stdio.h>

int main(){
    int n;
    int *pn = &n;
    printf("Informe a quantidade de valores: \n");
    scanf("%d", pn);
    int v[n];
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    int imenor = 0;
    int *pv = v + 1;
    for (i = 1; i < n; i++){
        if (*pv < v[imenor]){
            imenor = i;
        }
        pv++;
    }
    printf("MENOR: %d\n", imenor);
    return 0;
}