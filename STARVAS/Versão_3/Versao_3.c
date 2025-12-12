#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include <time.h> // Para a inicialização do srand
#include "historico.h"
#include <string.h>

// Definições
const int LARGURA = 1400;
const int ALTURA = 1000;
const float VELOCIDADE = 5.0f;
const float FPS = 60.0f;
const int TAMANHO_FONTE = 72;
const int MAX_ASTEROIDES = 500; 
const int FRAME_DELAY = 10; // Mantido para animação

// Enum para o estado do jogo
enum EstadoJogo {
    JOGANDO,
    GAME_OVER
};

typedef struct Node {
    char nome[50];
    struct Node *proximo;
}Node;

Node *lista_cabeca = NULL;

// Estrutura para rastrear o estado do teclado (Teclas pressionadas)
typedef struct
{
    int cima;
    int baixo;
    int esquerda;
    int direita;
} keyState;

// Estrutura do Asteroide
typedef struct {
    float x;
    float y;
    float velocidade_x;
    float raio; 
    bool ativo;
} Asteroide;

// Variáveis de Direção do Jogador
enum direcao {DIREITA, ESQUERDA};
const int FRAME_LARGURA = 64; 
const int FRAME_ALTURA = 64; 
const int FRAMES_POR_DIRECAO = 4; 
const float PLAYER_RAIO_COLISAO = 32.0f; // Raio de colisão do jogador

// Variáveis de Asteroide
// Tamanho original do sprite do asteroide (em pixels)
const float AST_LARGURA_SPRITE = 500.0f; 	
const float AST_RAIO_COLISAO = 16.0f;       // Raio de colisão (ex: 32px)

// ESCALA VISUAL: Define o tamanho do desenho (0.25 = 25% do sprite original)
const float AST_ESCALA_VISUAL = 0.125f;
const float AST_LARGURA_DESENHO = AST_LARGURA_SPRITE * AST_ESCALA_VISUAL; // Será 16.0f

// --- FUNÇÕES AUXILIARES ---

void inserir_nome_na_lista(const char *nome) {
    Node *novo_node = (Node *)malloc(sizeof(Node));
    if (novo_node == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria para a Lista.\n");
        return;
    }

    strcpy(novo_node->nome, nome);
    
    // Novo nó aponta para onde a cabeça apontava
    novo_node->proximo = lista_cabeca;
    
    // A cabeça aponta para o novo nó
    lista_cabeca = novo_node;
}

// Função Auxiliar: Cria um novo asteroide na borda da tela
void criar_asteroide(Asteroide *ast, int largura_tela, int altura_tela) {
    // Define o raio de colisão (32.0f)
    ast->raio = AST_RAIO_COLISAO; 

    // Posição inicial (fora da borda direita)
    ast->x = (float)largura_tela + ast->raio;
    ast->y = (float)(rand() % altura_tela);

    // Velocidade para a esquerda (aleatória)
    ast->velocidade_x = -(3.0f + (float)(rand() % 40) / 10.0f);

    ast->ativo = true;
}

// Função Auxiliar: Checagem de Colisão Simples (Raio a Raio)
bool checar_colisao(float x1, float y1, float r1, float x2, float y2, float r2) {
    // Distância euclidiana ao quadrado
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distancia_quadrado = dx * dx + dy * dy;

    // Soma dos raios ao quadrado
    float soma_raios = r1 + r2;
    float soma_raios_quadrado = soma_raios * soma_raios;

    return distancia_quadrado < soma_raios_quadrado;
}


// Função principal do jogo
int main(){
    FILE * file = fopen("historico.txt", "a");
    char nome_jogador[50];
    printf("Digite seu Nome:\n");
    scanf("%s", nome_jogador);
    inserir_nome_na_lista(nome_jogador);
    // Inicializa a semente para rand() apenas uma vez no início
    srand(time(NULL));

    // --------------------------------------------
    // 1. INICIALIZAÇÕES BÁSICAS
    // --------------------------------------------
    if (!al_init()){
        fprintf(stderr, "Falha ao iniciar o Allegro. \n");
        return -1;
    }

    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao receber informações do teclado.\n");
        return -1;
    }

    if (!al_init_primitives_addon()){
        fprintf(stderr, "Falha ao iniciar add-on de primitivas. \n");
        return -1;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao iniciar add-on de imagens. \n");
        return -1;
    }

    if (!al_init_font_addon()){
        fprintf(stderr, "Falha ao iniciar add-on de fonte. \n");
        return -1;
    }

    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao iniciar add-on TTF. \n");
        return -1;
    }


    // -------------------------------------------
    // 2. CRIAÇÃO DE RECURSOS
    // -------------------------------------------
    ALLEGRO_DISPLAY * display = al_create_display(LARGURA, ALTURA);
    if (!display){
        fprintf(stderr, "Falha ao criar o display. \n");
        return -1;
    }
    al_set_window_title(display, "STARVAS DEMO 1.0v");

    ALLEGRO_EVENT_QUEUE * fila_eventos = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);

    if (!fila_eventos || !timer){
          fprintf(stderr, "Falha ao criar fila de eventos ou timer.\n");
          al_destroy_display(display);
          al_destroy_event_queue(fila_eventos);
          al_destroy_timer(timer);
          return -1;
    }

    al_register_event_source(fila_eventos, al_get_display_event_source(display));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    ALLEGRO_FONT *font = al_load_font("arial.ttf", TAMANHO_FONTE, 0);
    if (!font) font = al_create_builtin_font(); // Tenta fonte embutida
    if (!font) {
        fprintf(stderr, "Falha ao carregar a fonte. \n"); 
        al_destroy_timer(timer); al_destroy_event_queue(fila_eventos); al_destroy_display(display); return -1;
    }

    // --- CARREGAMENTO DE SPRITES ---
    ALLEGRO_BITMAP *cenario_fundo = al_load_bitmap("cenario_amor1.png");
    ALLEGRO_BITMAP *personagem_sprite = al_load_bitmap("Personagem.png");
    ALLEGRO_BITMAP *asteroide_sprite = al_load_bitmap("asteroide_sprite.png"); 

    if (!cenario_fundo || !personagem_sprite || !asteroide_sprite){
        fprintf(stderr, "Falha ao carregar um ou mais sprites. Verifique os nomes dos arquivos.");
        al_destroy_timer(timer); al_destroy_font(font); al_destroy_event_queue(fila_eventos); al_destroy_display(display); 
        al_destroy_bitmap(cenario_fundo); al_destroy_bitmap(personagem_sprite); al_destroy_bitmap(asteroide_sprite);
        return -1;
    }


    // --- VARIÁVEIS DE JOGO E MOVIMENTO ---
    bool precisa_desenhar = true;
    double tempo_total = 0.0;
    float player_x = LARGURA / 2.0f; 
    float player_y = ALTURA / 2.0f; 
    keyState teclas = {0, 0, 0, 0};
    
    // --- VARIÁVEIS DE ANIMAÇÃO DO JOGADOR ---
    int frame_atual = 0; 
    int direcao_atual = DIREITA;
    int frame_contador = 0;

    // --- VARIÁVEIS DE COLISÃO E ASTEROIDE ---
    Asteroide asteroides[MAX_ASTEROIDES];
    enum EstadoJogo estado_atual = JOGANDO;

    // Inicialização dos Asteroides
    for (int i = 0; i < MAX_ASTEROIDES; i++){
        asteroides[i].ativo = false; 
        asteroides[i].raio = AST_RAIO_COLISAO; // Inicializa com o raio de colisão de 32.0f
    }
    al_rest(3.0);
    al_start_timer(timer);


    // -------------------------------------------
    // 3. O LOOP PRINCIPAL DO JOGO
    // -------------------------------------------
    bool rodando = true;
    ALLEGRO_EVENT evento; 

    while (rodando){
        al_wait_for_event(fila_eventos, &evento);

        // --- LÓGICA DE EVENTOS (Teclado e Fechar Janela) ---

        // Se o estado é GAME_OVER, só permite o ESC para sair
        if (estado_atual == GAME_OVER && evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            rodando = false;
        } 
        
        if (estado_atual == JOGANDO) {
            // 1. Tecla Pressionada (KEY_DOWN)
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch (evento.keyboard.keycode){
                    case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W: teclas.cima = 1; break;
                    case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S: teclas.baixo = 1; break;
                    case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A: teclas.esquerda = 1; break;
                    case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D: teclas.direita = 1; break;
                    case ALLEGRO_KEY_ESCAPE: rodando = false; break;
                }
            }
            // 2. Tecla liberada (KEY_UP)
            if (evento.type == ALLEGRO_EVENT_KEY_UP){
                switch (evento.keyboard.keycode){
                    case ALLEGRO_KEY_UP: case ALLEGRO_KEY_W: teclas.cima = 0; break;
                    case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_S: teclas.baixo = 0; break;
                    case ALLEGRO_KEY_LEFT: case ALLEGRO_KEY_A: teclas.esquerda = 0; break;
                    case ALLEGRO_KEY_RIGHT: case ALLEGRO_KEY_D: teclas.direita = 0; break;
                }
            }
        }

        // 3. Fechar Janela
        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            rodando = false;
        }

        // --- TRATAMENTO DO TEMPO (LÓGICA DO JOGO) ---
        else if (evento.type == ALLEGRO_EVENT_TIMER){

            precisa_desenhar = true;

            if (estado_atual == JOGANDO){
                tempo_total += 1.0 / FPS;
                // --- OBTENDO RAIO DE COLISÃO DO JOGADOR ---
                // Não precisamos recalcular, usamos a constante PLAYER_RAIO_COLISAO

                // --- LÓGICA DE ATUALIZAÇÃO (MOVIMENTO) E DIREÇÃO ---
                bool esta_movendo = false; 

                if (teclas.cima) { player_y -= VELOCIDADE; esta_movendo = true; }
                if (teclas.baixo) { player_y += VELOCIDADE; esta_movendo = true; }
                if (teclas.esquerda) { player_x -= VELOCIDADE; direcao_atual = ESQUERDA; esta_movendo = true; }
                if (teclas.direita) { player_x += VELOCIDADE; direcao_atual = DIREITA; esta_movendo = true; }

                // --- LÓGICA DE COLISÃO DE BORDA DO JOGADOR ---
                if (player_x < PLAYER_RAIO_COLISAO) player_x = PLAYER_RAIO_COLISAO;
                if (player_x > LARGURA - PLAYER_RAIO_COLISAO) player_x = LARGURA - PLAYER_RAIO_COLISAO;
                if (player_y < PLAYER_RAIO_COLISAO) player_y = PLAYER_RAIO_COLISAO;
                if (player_y > ALTURA - PLAYER_RAIO_COLISAO) player_y = ALTURA - PLAYER_RAIO_COLISAO; 

                // --- LÓGICA DE ASTEROIDES ---
                
                // 1. Criação: Chance de 1 em 60 ticks (1 vez por segundo, em média)
                int dificuldade_base = 30;
                int dificuldade_atual;
                dificuldade_atual = dificuldade_base - (int)floor(tempo_total/3.0);
                if (dificuldade_atual < 10){
                    dificuldade_atual = 2;
                }

                if (rand() % dificuldade_atual == 0) {
                    for (int i = 0; i < MAX_ASTEROIDES; i++) {
                        if (!asteroides[i].ativo) {
                            criar_asteroide(&asteroides[i], LARGURA, ALTURA);
                            break;
                        }
                    }
                }
                
                // 2. Movimento e Colisão
                for (int i = 0; i < MAX_ASTEROIDES; i++) {
                    if (asteroides[i].ativo) {
                        // Movimento
                        asteroides[i].x += asteroides[i].velocidade_x;
                        
                        // Checagem de Colisão
                        if (checar_colisao(player_x, player_y, PLAYER_RAIO_COLISAO,
                                             asteroides[i].x, asteroides[i].y, asteroides[i].raio)) {
                            estado_atual = GAME_OVER; // JOGO ACABA!
                            break; 
                        }

                        // Destruição (se saiu da tela)
                        if (asteroides[i].x < -asteroides[i].raio) {
                            asteroides[i].ativo = false;
                        }
                    }
                }

                // --- LÓGICA DE ANIMAÇÃO ---
                if (esta_movendo){
                    frame_contador++;
                    if (frame_contador >= FRAME_DELAY){
                        frame_contador = 0;
                        frame_atual = (frame_atual + 1) % FRAMES_POR_DIRECAO; // Loop entre 0 e 3
                    }
                }
                else{
                    frame_atual = 0;
                    frame_contador = 0;
                }

            } // Fim: if (estado_atual == JOGANDO)
        }
    
        // --- LÓGICA DE DESENHO (RENDERIZAÇÃO) ---
        if (precisa_desenhar){
            al_clear_to_color(al_map_rgb(0, 0, 0));

            // --- CÁLCULO DO CRONÔMETRO ---
            int minutos = (int)floor(tempo_total / 60.0);
            int segundos = (int)floor(fmod(tempo_total, 60.0));
            char tempo_string[10]; 
            sprintf(tempo_string, "%02d:%02d", minutos, segundos);
            // --------------------------------------------------

            // 1. Desenha o cenário de fundo
            al_draw_bitmap(cenario_fundo, 0, 0, 0);

            // Desenha o jogador e asteroides (em ambos os estados para mostrar a colisão)
            if (estado_atual == JOGANDO || estado_atual == GAME_OVER) {

                // --- DESENHO DO JOGADOR (Sprite Region) ---
                float offset_x = (direcao_atual == ESQUERDA) ? 0.0f : (float)FRAMES_POR_DIRECAO * FRAME_LARGURA;
                float sx = offset_x + (float)frame_atual * FRAME_LARGURA;

                al_draw_bitmap_region(
                    personagem_sprite, 
                    sx, 0, // sy é 0
                    (float)FRAME_LARGURA, (float)FRAME_ALTURA, 
                    player_x - PLAYER_RAIO_COLISAO, // Centraliza o sprite 64x64
                    player_y - PLAYER_RAIO_COLISAO, 
                    0
                );

                // --- DESENHO DOS ASTEROIDES (CORRIGIDO: ESCALADO PARA 16x16) ---
                for (int i = 0; i < MAX_ASTEROIDES; i++) {
                    if (asteroides[i].ativo) {

                        // Desenha o asteroide escalado (16x16), centralizado na posição de colisão
                        al_draw_scaled_bitmap(
                            asteroide_sprite,
                            0, 0,
                            AST_LARGURA_SPRITE, AST_LARGURA_SPRITE, // Recorta o sprite 64x64
                            
                            // Posição de Desenho (Centraliza o sprite desenhado (16x16) no ponto ast.x)
                            asteroides[i].x - (AST_LARGURA_DESENHO / 2.0f),
                            asteroides[i].y - (AST_LARGURA_DESENHO / 2.0f),
                            
                            // Largura e Altura de Desenho (16x16)
                            AST_LARGURA_DESENHO,
                            AST_LARGURA_DESENHO,
                            0
                        );
                    }
                }
                
                // --- Desenho do Cronômetro (APENAS SE ESTIVER JOGANDO) ---
                if (estado_atual == JOGANDO) {
                    ALLEGRO_COLOR cor_tempo = al_map_rgb(255, 255, 255);
                    al_draw_text(font, cor_tempo, LARGURA - 20, 10, ALLEGRO_ALIGN_RIGHT, tempo_string);
                }
            }

            // --- TELA DE GAME OVER ---
            if (estado_atual == GAME_OVER) {
                ALLEGRO_COLOR cor_vermelha = al_map_rgb(255, 0, 0);
                ALLEGRO_COLOR cor_branca = al_map_rgb(255, 255, 255);
                
                al_draw_text(
                    font,
                    cor_vermelha,
                    LARGURA / 2.0f, ALTURA / 2.0f - TAMANHO_FONTE * 1.5f,
                    ALLEGRO_ALIGN_CENTER,
                    "GAME OVER"
                );
                
                // Exibe o tempo que o jogador durou (USA tempo_string)
                char score_text[50];
                sprintf(score_text, "Voce durou: %s", tempo_string);
                al_draw_text(
                    font,
                    cor_branca,
                    LARGURA / 2.0f, ALTURA / 2.0f - TAMANHO_FONTE / 2.0f,
                    ALLEGRO_ALIGN_CENTER,
                    score_text
                );

                al_draw_text(
                    font,
                    cor_branca,
                    LARGURA / 2.0f, ALTURA / 2.0f + TAMANHO_FONTE * 0.5f,
                    ALLEGRO_ALIGN_CENTER,
                    "Pressione ESC para Sair"
                );
            }

            // 3. Manda desenhar tudo na tela
            al_flip_display();
            precisa_desenhar = false;
        }
    }
    salvar_e_ordenar_historico(nome_jogador, tempo_total);
    // ------------------------------------------
    // 4. LIMPEZA (DESTRUIÇÃO DE RECURSOS)
    // ------------------------------------------

    Node *atual = lista_cabeca;
    Node *proximo_node;
    while (atual != NULL){
        proximo_node = atual->proximo;
        free(atual);
        atual = proximo_node;
    }

    al_destroy_timer(timer);
    al_destroy_bitmap(cenario_fundo);
    al_destroy_bitmap(personagem_sprite);
    al_destroy_bitmap(asteroide_sprite);
    al_destroy_font(font);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(display);
    
    return 0;
}