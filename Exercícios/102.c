#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome_feitico[50];
    int custo_mana;
} Feitico;

struct no {
    Feitico dado;
    struct no *prox;
};

typedef struct no No;

typedef struct {
    No *topo;
} Pilha;

// Ler dados do feitiço
void ler(Feitico *pe) {
    scanf("%s %d", pe->nome_feitico, &pe->custo_mana);
}

// Inserir no topo da pilha
void inserir(Pilha *ppilha, Feitico dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

// Remover e retornar o topo da pilha
Feitico pop(Pilha *p) {
    Feitico erro;
    erro.custo_mana = -1;  // indica erro

    if (p->topo == NULL) {
        printf("A pilha de comandos esta vazia!\n");
        return erro;
    }

    No *remover = p->topo;
    Feitico resultado = remover->dado;

    p->topo = remover->prox;
    free(remover);

    return resultado;
}

// Mostrar a pilha do topo para a base
void mostrar_pilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }

    No *pi = p->topo;
    printf("\n--- PILHA DE COMANDOS ---\n");
    while (pi != NULL) {
        printf("Feitico: %s | Custo: %d\n", pi->dado.nome_feitico, pi->dado.custo_mana);
        pi = pi->prox;
    }
    printf("-------------------------\n");
}

// Liberar toda a memória da pilha
void liberar_pilha(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
}

void menu() {
    printf("Escolha a opcao:\n");
    printf("1 - Adicionar novo feitico à pilha de comandos\n");
    printf("2 - Lançar próximo feitiço (POP)\n");
    printf("3 - Mostrar pilha de comandos\n");
    printf("4 - Finalizar e sair\n");
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 4) {

        if (op == 1) {
            Feitico f;
            printf("Informe o nome e o custo de mana:\n");
            ler(&f);
            inserir(&pilha, f);
        }

        else if (op == 2) {
            Feitico f = pop(&pilha);
            if (f.custo_mana != -1) {
                printf("Feitico '%s' lançado com sucesso!\n", f.nome_feitico);
            }
        }

        else if (op == 3) {
            mostrar_pilha(&pilha);
        }

        menu();
        scanf("%d", &op);
    }

    liberar_pilha(&pilha);
    return 0;
}
