#include <stdio.h>

int main(){
    int n;
    printf("Digite o n:\n");
    scanf("%d", &n);
    for (int i = n; i > 1; i/2){
        printf("%d", i);
    }
    return 0;
}