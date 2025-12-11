#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=====================================
// STRUCTS
//=====================================

typedef struct {
    char nome[50];
    int poder;
} Feitico;

typedef struct No {
    Feitico dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;


//=====================================
// FUNÇÕES DA PILHA
//=====================================

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = f;
    novo->prox = p->topo;
    p->topo = novo;
}

Feitico pop(Pilha *p) {
    Feitico f = {"", 0};

    if (vazia(p)) return f;

    No *aux = p->topo;
    f = aux->dado;
    p->topo = aux->prox;
    free(aux);
    return f;
}

//=====================================
// inverter_pilha (já usada em aula)
//=====================================

void inverter_pilha(Pilha *p) {
    Pilha aux1, aux2;
    inicializar(&aux1);
    inicializar(&aux2);

    while (!vazia(p))
        push(&aux1, pop(p));

    while (!vazia(&aux1))
        push(&aux2, pop(&aux1));

    while (!vazia(&aux2))
        push(p, pop(&aux2));
}


//=====================================
// NOVA FUNÇÃO: carregar_pilha_de_arquivo
//=====================================

void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "rb");

    if (!arq) {
        printf("Nenhum grimório encontrado, iniciando com uma pilha vazia.\n");
        return;  // Não é erro. Apenas significa que nunca foi salvo antes.
    }

    Feitico f;
    while (fread(&f, sizeof(Feitico), 1, arq) == 1) {
        push(p, f);  // Isso INVERTE a ordem durante o carregamento
    }

    fclose(arq);

    // IMPORTANTE: restaurar ordem correta
    inverter_pilha(p);

    printf("Grimório carregado com sucesso!\n");
}


//=====================================
// salvar_pilha_em_arquivo (para completar)
//=====================================

void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "wb");
    if (!arq) {
        printf("Erro ao salvar grimório!\n");
        return;
    }

    Pilha aux;
    inicializar(&aux);

    // preservar a pilha
    while (!vazia(p)) {
        Feitico f = pop(p);
        fwrite(&f, sizeof(Feitico), 1, arq);
        push(&aux, f);
    }

    // devolve itens para a pilha original
    while (!vazia(&aux))
        push(p, pop(&aux));

    fclose(arq);
}


//=====================================
// MOSTRAR
//=====================================

void exibir_pilha(Pilha *p) {
    Pilha aux;
    inicializar(&aux);

    while (!vazia(p)) {
        Feitico f = pop(p);
        printf("Feitiço: %s | Poder: %d\n", f.nome, f.poder);
        push(&aux, f);
    }

    // restaura
    while (!vazia(&aux))
        push(p, pop(&aux));
}


//=====================================
// MAIN
//=====================================

int main() {
    Pilha grimorio;
    inicializar(&grimorio);

    // 🔥 Carrega automaticamente o estado salvo
    carregar_pilha_de_arquivo(&grimorio, "grimorio.bin");

    int opc;
    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar feitiço\n");
        printf("2 - Remover feitiço\n");
        printf("3 - Mostrar grimorio\n");
        printf("4 - Salvar grimorio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);
        getchar();

        if (opc == 1) {
            Feitico f;
            printf("Nome do feitiço: ");
            fgets(f.nome, 50, stdin);
            f.nome[strcspn(f.nome, "\n")] = 0;

            printf("Poder: ");
            scanf("%d", &f.poder);

            push(&grimorio, f);

        } else if (opc == 2) {
            if (!vazia(&grimorio)) {
                Feitico f = pop(&grimorio);
                printf("Removido: %s\n", f.nome);
            } else {
                printf("Grimório vazio.\n");
            }

        } else if (opc == 3) {
            exibir_pilha(&grimorio);

        } else if (opc == 4) {
            salvar_pilha_em_arquivo(&grimorio, "grimorio.bin");
            printf("Grimório salvo!\n");
        }

    } while (opc != 0);

    return 0;
}
