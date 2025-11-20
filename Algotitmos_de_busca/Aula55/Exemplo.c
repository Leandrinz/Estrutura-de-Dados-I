// Busca binária
#include <stdio.h>

struct estudante
{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

void ler(struct estudante *pe){
    scanf("%d %s %f %f %f", &pe->matricula, pe->nome, &pe->nota1, &pe->nota2, &pe->nota3);
}

void menu(){
    printf("====== Digite a opcao ======\n");
    printf("1 - Pesquisar \n");
    printf("2 - Sair\n");
    printf("============================\n");
}

// Para a busca ser realizada com sucesso, o vetor tem que estar ordenado
int buscabinaria(int matricula, int numero_total, struct estudante v[]){
    int i = 0; // Onde a busca começa
    int f = numero_total - 1; // Até onde a busca vai
    while (i <= f){
        int meio = (i + f)/ 2; 
        if (v[meio].matricula == matricula){ // Caso a matrícula buscada seja a procurada
            return meio; // Retorna a posição achada caso dê tudo certo
        }
        else if (v[meio].matricula < matricula){ // Caso a matrícula seja menor que a matrícula, temos que avançar e buscar pra frente
            i = meio + 1; // Avançamos um na busca para buscarmos a matrícula
        }
        else{
            f = meio - 1;
        }
    }
    return -1;
}

int main(){
    int numero_total;
    printf("Informe o numero total de estudantes:\n");
    scanf("%d", &numero_total);
    struct estudante v[numero_total];
    int i;
    for (i = 0; i < numero_total; i++){
        ler(&v[i]);
    }
    int opcao;
    menu();
    scanf("%d", &opcao);
    while (opcao != 2){
        if (opcao == 1){
            int matricula;
            printf("Informe a matricula:\n");
            scanf("%d", &matricula);
            int idx = buscabinaria(matricula, numero_total, v);
            if (idx != -1){
                v[idx].nota3 = v[idx].nota3 + 1;
                float media = (v[idx].nota1 * 2 + v[idx].nota2 * 3 + v[idx].nota3 * 4) / 9;
                printf("%s:%.2f\n", v[idx].nome, media);
            }
        }
        menu();
        scanf("%d", &opcao);
    }
    printf("Programa finalizado!\n");
}