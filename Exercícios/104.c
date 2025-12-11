#include <stdio.h>
#include <stdlib.h>

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

void ler(Feitico *pe) {
    scanf("%s %d", pe->nome_feitico, &pe->custo_mana);
}

int vazia(Pilha *p) {
    return (p->topo == NULL);
}

void inserir(Pilha *ppilha, Feitico dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = ppilha->topo;
    ppilha->topo = novo;
}

Feitico pop(Pilha *p) {
    Feitico erro;
    erro.custo_mana = -1;

    if (vazia(p)) {
        printf("A pilha de comandos esta vazia!\n");
        return erro;
    }

    No *aux = p->topo;
    Feitico retirado = aux->dado;
    p->topo = aux->prox;
    free(aux);

    return retirado;
}

Feitico top(Pilha *p) {
    Feitico erro;
    erro.custo_mana = -1;

    if (vazia(p)) {
        printf("A pilha de comandos esta vazia!\n");
        return erro;
    }

    return p->topo->dado;
}

void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }

    No *pi = p->topo;
    while (pi != NULL) {
        printf("%s %d\n", pi->dado.nome_feitico, pi->dado.custo_mana);
        pi = pi->prox;
    }
}

void liberar_pilha(Pilha *p) {
    while (!vazia(p)) {
        pop(p);
    }
}

void menu() {
    printf("\n--- MENU DO ARCANISTA ---\n");
    printf("1 - Adicionar novo feitico\n");
    printf("2 - Lancar proximo feitico (pop)\n");
    printf("3 - Mostrar pilha de comandos\n");
    printf("4 - Consultar proximo feitico (top)\n");
    printf("5 - Verificar status da pilha\n");
    printf("6 - Sair\n");
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;

    int op;
    menu();
    scanf("%d", &op);

    while (op != 6) {

        if (op == 1) {
            Feitico f;
            printf("Informe o nome e o custo de mana do feitico:\n");
            ler(&f);
            inserir(&pilha, f);
        }

        else if (op == 2) {
            Feitico fx = pop(&pilha);
            if (fx.custo_mana != -1) {
                printf("Feitico '%s' lancado com sucesso!\n", fx.nome_feitico);
            }
        }

        else if (op == 3) {
            mostrar_pilha(&pilha);
        }

        else if (op == 4) {
            Feitico topo = top(&pilha);
            if (topo.custo_mana != -1) {
                printf("Proximo feitico: %s (Custo: %d)\n", topo.nome_feitico, topo.custo_mana);
            }
        }

        else if (op == 5) {
            if (vazia(&pilha))
                printf("A pilha de comandos esta vazia.\n");
            else
                printf("A pilha de comandos possui feitiços pendentes.\n");
        }

        menu();
        scanf("%d", &op);
    }

    liberar_pilha(&pilha);
    return 0;
}
