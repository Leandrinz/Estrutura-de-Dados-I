#include <stdio.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

int particao(int e, int d, Jogador v[]) {
    Jogador pivo = v[d];
    int j = e - 1;

    for (int i = e; i < d; i++) {
        if (v[i].pontuacao >= pivo.pontuacao) {
            j++;
            Jogador temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }

    Jogador temp = v[j + 1];
    v[j + 1] = v[d];
    v[d] = temp;

    return j + 1;
}

void quicksort(int e, int d, Jogador v[]) {
    if (e < d) {
        int p = particao(e, d, v);
        quicksort(e, p - 1, v);
        quicksort(p + 1, d, v);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Jogador jogadores[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }

    quicksort(0, n - 1, jogadores);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }

    return 0;
}
