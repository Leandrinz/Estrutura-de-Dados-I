#include <stdio.h>

void ler_cenario(int n, int cenario[]){
    for (int i = 0; i < n; i++){
        scanf("%d", cenario + i);
    }
}


int main(){
    int n;
    int *pn = &n;
    printf("Digite o numero de blocos: \n");
    scanf("%d", pn);
    int cenario[n];
    ler_cenario(n, cenario);
    for (int c = 0; c < n; c++){
        if (*(cenario + c) == 1){
            *(cenario + c) = 2;
            break;
        }
    }
    for (int c = 0; c < n; c++){
        printf("%d ", *(cenario + c));
    }




    return 0;
}