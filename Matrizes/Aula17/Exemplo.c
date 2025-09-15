// Manipulando Matrizes //
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int n;
    int *pn = &n;
    
    printf("Digite um valor para n: \n ");
    scanf("%d", pn);
    
    // Cria uma matriz n x n, n esse � o n�mero que o usu�rio digitou!
    int matriz[n][n];
    int coluna, linha;
    
    // Cria a matriz com valores recebidos pelo usu�rio
    for (coluna = 0; coluna < n; coluna++){
       
        for (linha = 0; linha < n; linha++){

            scanf("%d", &matriz[coluna][linha]);
        }
    }
    // Recebe o valor que o usu�rio quer achar na matriz
    int numero_procurado;
    int *ponteiro_numero_procurado = &numero_procurado;
    printf("Digite o n�mero que voc� quer achar na matriz: ");
    scanf("%d", ponteiro_numero_procurado);

    // Exibe a matriz e mostra onde o n�mero procurado est�.
    for (coluna = 0; coluna < n; coluna++){
        for (linha = 0; linha < n; linha++){

            printf("%d ", matriz[coluna][linha]);
        
        }
        
        printf("\n");
    }

    for (coluna = 0; coluna < 3; coluna++){
        for (linha = 0; linha < 3; linha++){

            if (*ponteiro_numero_procurado == matriz[coluna][linha]){
                printf("O n�mero %d est� na coluna %d, linha %d.", *ponteiro_numero_procurado, coluna, linha);
            }
        
        }
        
        printf("\n");
    }

    return 0;
}