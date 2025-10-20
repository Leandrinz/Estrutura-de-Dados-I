#include <stdio.h>

struct Atributos
{
    int vida;
    int pontuacao;
};


struct Personagem
{
    char nome[50];
    struct Atributos stats;
};


int main(){
    struct Personagem Jogador;
    
    printf("Digite o nome do personagem: \n");
    scanf("%s", &Jogador.nome);
    
    Jogador.stats.vida = 100;
    Jogador.stats.pontuacao = 0;

    printf("Status Inicial -> Nome: %s | Vida: %d | Pontuacao: %d\n", Jogador.nome, Jogador.stats.vida, Jogador.stats.pontuacao);

    Jogador.stats.vida -= 25;
    Jogador.stats.pontuacao += 10;

    printf("Status Inicial -> Nome: %s | Vida: %d | Pontuacao: %d", Jogador.nome, Jogador.stats.vida, Jogador.stats.pontuacao);

    return 0;
}
