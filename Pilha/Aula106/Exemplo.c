// Salvando a pilha em um arquivo
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;
    char nome[50];
}estudante;

struct no{
    estudante dado;
    struct no * prox;
};

typedef struct no No;

typedef struct {
    No * topo;
}Pilha;

void menu(){
    printf("==== escolha uma opcao ====\n");
    printf("1 - adicionar\n");
    printf("2 - Mostrar pilha\n");
    printf("3 - Remover\n");
    printf("4 - vazia\n");
    printf("5 - Topo\n");
    printf("6 - Inverter\n");
    printf("7 - Salvar\n");
    printf("8 - Sair\n");
    printf("===========================\n");
}

void ler(estudante *pe){
    scanf("%d %s", &pe->mat, pe->nome);
}
//push
void inserir(Pilha *ppilha, estudante dado){
    No * novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}
// pop
void remover(Pilha *ppilha){
    if (ppilha->topo == NULL){
        printf("A pilha esta vazia\n");
    }
    else{
        No * pi = ppilha->topo;
        ppilha->topo = pi->prox;
        free(pi);
    }
}
// is empyt
int vazia(Pilha pilha){
    if (pilha.topo == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

No * topo(Pilha pilha){
    return pilha.topo;
}

void mostrar_pilha(Pilha pilha){
    No * pi;
    for (pi = pilha.topo; pi != NULL; pi = pi->prox){
        printf("%d %s\n", pi->dado.mat, pi->dado.nome);
    }
}

void inverter(Pilha *ppilha){
    Pilha aux;
    aux.topo = NULL;
    No * pi;
    for (pi = ppilha->topo; pi != NULL; pi = ppilha->topo){
        inserir(&aux, pi->dado);
        remover(ppilha);
    }
    ppilha->topo = aux.topo;
}

void salvar(Pilha pilha){
    FILE * file = fopen("./estudantes.b", "wb");
    No * pi;
    for (pi = pilha.topo; pi != NULL; pi = pi->prox){
        fwrite(&pi->dado, sizeof(estudante), 1, file);
    }
    fclose(file);
}

int main(){
    Pilha pilha;
    pilha.topo = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 8){
        if (op == 1){
            estudante e;
            printf("Informe os dados do estudante\n");
            ler(&e);
            inserir(&pilha, e);
        }
        else if (op == 2){
            mostrar_pilha(pilha);
        }
        else if (op == 3){
            remover(&pilha);
        }
        else if (op == 4){
            int r;
            r = vazia(pilha);
            if (r == 1){
                printf("Pilha esta vazia\n");
            }
            else{
                printf("A pilha nao esta vazia\n");
            }
        }
        else if (op == 5){
            No * pi = topo(pilha);
            if (pi == NULL){
                printf("pilha vazia\n");
            }
            else{
                printf("%s:%d", pi->dado.nome, pi->dado.mat);
            }
        }
        else if (op == 6){
            inverter(&pilha);
        }
        else if (op == 7){
            salvar(pilha);
        }
        menu();
        scanf("%d", &op);
    }
    return 0;   
}