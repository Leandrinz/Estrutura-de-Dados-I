#include <stdio.h>
#include "personagem.h"

int main() {
    int n;

    printf("Quantos membros tera a equipe? ");
    scanf("%d", &n);

    Personagem* equipe = cria_party(n);

    if (equipe == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    registra_membros(equipe, n);

    exibe_relatorio(equipe, n);

    libera_party(equipe);

    return 0;
}
