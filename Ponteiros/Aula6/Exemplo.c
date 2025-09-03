#include <stdio.h>

int main(){
    int n, i, men;
    int *pn = &n;
    int v[*pn];
    scanf("%d", pn);
    for (i = 0; i < *pn; i++){
        scanf("%d", v + i); // Como v já é um endereço de memória, nn precisa do &.
        if (i == 0){
            men = *(v + i);
        }
        if (*(v + i) < men){
            men = *(v + i);
        }
    }
    printf("Menor: %d", men);
    return 0;
}