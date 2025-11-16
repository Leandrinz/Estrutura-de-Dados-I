#include <allegro5/allegro5.h> // Importa o allegro5
#include <allegro5/allegro_primitives.h> // Para desenhar formas simples
#include <allegro5/allegro_image.h> // Carregar imagens (PNG E OUTRAS)
#include <stdio.h>
#include <allegro5/allegro_font.h> // Para desenhar texto
#include <allegro5/allegro_ttf.h> // Para carrefar fontes TrueType
#include <math.h> // Para a função floor, bom para cálculo do tempo
#include <allegro5/allegro.h>

// Definições
const int LARGURA = 1400;
const int ALTURA = 1000;
const float VELOCIDADE = 5.0f;
const float FPS = 60.0f;
const int TAMANHO_FONTE = 72;

// Estrutura para rastrear o estado do teclado (Teclas pressionadas)
typedef struct
{
    int cima;
    int baixo;
    int esquerda;
    int direita;
} keyState;


// Função principal do jogo
int main(){




    // --------------------------------------------
    // 1. INICIALIZAÇÕES BÁSICAS
    // --------------------------------------------
    if (!al_init()){
        fprintf(stderr, "Falha ao iniciar o Allegro. \n");
        return -1;
    }

    // Inicializando o módulo de teclado para receber eventos de tecla
    if(!al_install_keyboard()){
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
    }
    al_set_window_title(display, "STARVAS DEMO 1.0v");

    // cria a fila de eventos (onde o allegro coloca os eventos)
    ALLEGRO_EVENT_QUEUE * fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar a fila de eventos. \n");
        al_destroy_display(display);
        return -1;
    }

    // Registro as fontes de evento que queremos monitorar
    al_register_event_source(fila_eventos, al_get_display_event_source(display));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    // --- TEMPORIZADOR PARA FPS ---
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS); // 1.0 / 60.0 = intervalo de tempo em segundos
    if (!timer){
        fprintf(stderr, "Falha ao iniciar o temporizador. \n");
        // Limpa os recursos usados
        al_destroy_display(display);
        al_destroy_event_queue(fila_eventos);
        return -1;
    } 

    // Registrar a fonte de evento do timer
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    // Variável de controle (para saber se é preciso desenhar)
    bool precisa_desenhar = true; // Começa com true para desenhar o primeiro quadro

    // Inicia o temporizador
    al_start_timer(timer);

    // --- Carregamento da Fonte ---
    ALLEGRO_FONT *font = al_load_font("arial.ttf", TAMANHO_FONTE, 0);

    if (!font){
        // Tenta usar a fonte embutida se o arquivo não carregar
        font = al_create_builtin_font();
        if (!font){
            fprintf(stderr, " Falha ao carregar a fonte, mesmo a embutida. \n");
            // Limpa os recursos e sai
            al_destroy_timer(timer);
            al_destroy_event_queue(fila_eventos);
            al_destroy_display(display);
            return -1;
        }
    }
    double tempo_total = 0.0;

    // --- VARIÁVEIS DE MOVIMENTO ---
    float player_x = LARGURA / 2.0f; // Posição X inicial (float para o movimento suave)
    float player_y = ALTURA / 2.0f; // Posição Y inicial
    keyState teclas = {0, 0, 0, 0}; // Inicializa todas as teclas com 0 (não pressionadas)


    // --- VARIÁVEIS DE ANIMAÇÃO ---
    int frame_atual = 0; // índice do frame a ser desenhado (0 a 7)
    const int FRAME_LARGURA = 64;
    const int FRAME_ALTURA = 64;

    // A animação terá 4 frames por direção (0, 1, 2, 3)
    const int FRAMES_POR_DIRECAO = 4;
    const int FRAME_MAXIMO = FRAMES_POR_DIRECAO - 1; // Índice máximo: 3

    // Variável para determinar a direção do sprite (DIREITA = 0, ESQUERDA = 1)
    enum direcao {DIREITA, ESQUERDA};
    int direcao_atual = DIREITA;

    // Variável para controlar a velocidade da animação (Troca de frame a cada 10 game Ticks)
    int frame_contador = 0;
    const int FRAME_DELAY = 10;


    // DECLARAÇÃO E CARREGAMENTO DO SPRITE DE FUNDO
    ALLEGRO_BITMAP *cenario_fundo = al_load_bitmap("cenario_amor1.png");

    // Checagem de segurança 
    if (!cenario_fundo){
        fprintf(stderr, "Falha ao carregar o sprite de fundo 'fundo.png'.");
        // Limpar recursos antes de sair
        al_destroy_event_queue(fila_eventos);
        al_destroy_display(display);
        return -1;
    }

    // DECLARAÇÃO E CARREGAMENTO DO SPRITE DO PERSONAGEM
    ALLEGRO_BITMAP *personagem_sprite = al_load_bitmap("Personagem.png");

    // Checagem de segurança 
    if(!personagem_sprite){
        fprintf(stderr, "Falha ao carregar o sprite do personagem!");
        // Limpar recursos antes de sair
        al_destroy_bitmap(cenario_fundo);
        al_destroy_event_queue(fila_eventos);
        al_destroy_display(display);
        return -1;
    }




    // -------------------------------------------
    // 3. O LOOP PRINCIPAL DO JOGO
    // -------------------------------------------
    bool rodando = true;
    ALLEGRO_EVENT evento; // Variável onde o evento lido será armazenado

    while (rodando){
        al_wait_for_event(fila_eventos, &evento);


        // Espera por um evento. A função al_wait_for_event() trava o programa até que o evento ocorra.

        // --- LÓGICA DE EVENTOS ---

        // 1. Tecla Pressionada (KEY_DOWN)
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
            switch (evento.keyboard.keycode){
            case ALLEGRO_KEY_UP:
            case ALLEGRO_KEY_W:
            teclas.cima = 1;
            break;
            case ALLEGRO_KEY_DOWN:
            case ALLEGRO_KEY_S:
            teclas.baixo = 1;
            break;
            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
            teclas.esquerda = 1;
            break;
            case ALLEGRO_KEY_RIGHT:
            case ALLEGRO_KEY_D:
            teclas.direita = 1;
            break;
            case ALLEGRO_KEY_ESCAPE:
            rodando = false;
            break;
            }
        }
        // 2. Tecla liberada (KEY_UP)
        if (evento.type == ALLEGRO_EVENT_KEY_UP){
            switch (evento.keyboard.keycode){
            case ALLEGRO_KEY_UP:
            case ALLEGRO_KEY_W:
            teclas.cima = 0;
                break;
            case ALLEGRO_KEY_DOWN:
            case ALLEGRO_KEY_S:
                teclas.baixo = 0;
                break;
            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
                teclas.esquerda = 0;
                break;
            case ALLEGRO_KEY_RIGHT:
            case ALLEGRO_KEY_D:
                teclas.direita = 0;
                break;
            }
        }

        // 3. Fechar Janela
        else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                rodando = false;
        }

        // --- TRATAMENTO DO TEMPO (LÓGICA DO JOGO) ---
        // Esse é o único momento em que o player_x e player_y é atualizado

        else if (evento.type == ALLEGRO_EVENT_TIMER){

            precisa_desenhar = true;

            // Incrementa o tempo total de jogo (a cada "tick" do timer)
            tempo_total += 1.0 / FPS;

            // --- OBTENDO DIMENSÕES DO SPRITE PARA CÁLCULO DE COLISÃO ---
            
            // Calcula o raio (metade) da largura e altura
            float raio_x = FRAME_LARGURA / 2.0f;
            float raio_y = FRAME_ALTURA / 2.0f;

            // --- LÓGICA DE ATUALIZAÇÃO (MOVIMENTO) E DIREÇÃO ---
            // Se uma tecla é pressionada (1), move a posição

            bool esta_movendo = false; // Flag para a animação

            if (teclas.cima){
                player_y -= VELOCIDADE;
                esta_movendo = true;
            }
            if (teclas.baixo){
                player_y += VELOCIDADE;
                esta_movendo = true;
            }
            if (teclas.esquerda){
                player_x -= VELOCIDADE;
                direcao_atual = ESQUERDA;
                esta_movendo = true;
            }
            if (teclas.direita){
                player_x += VELOCIDADE;
                direcao_atual = DIREITA;
                esta_movendo = true;
            }

            // --- LÓGICA DE COLISÃO DE BORDA ---
            
            // Colisão Eixo X (Horizontal)
            if (player_x < raio_x){
                player_x = raio_x; // Bateu na esquerda
            }
            if (player_x > LARGURA - raio_x){
                player_x = LARGURA - raio_x; // Bateu na direita
            }

            // Colisão Eixo Y (Vertical)
            if (player_y < raio_y){
                player_y = raio_y; // Bateu no topo
            }
            if (player_y > ALTURA - raio_y){
                player_y = ALTURA - raio_y;
            } 

            if (esta_movendo){
                frame_contador++;

                if (frame_contador >= FRAME_DELAY){
                    frame_contador = 0;
                    frame_atual++;
                    // Reseta a animação (volta de 3 para 0, ou de 7 para 4)
                    if (frame_atual >= FRAMES_POR_DIRECAO){
                        frame_atual = 0; // Reseta o índice dentro do bloco de 4 frames
                    }
                }
            }
            else{
                // Se não estiver se movendo, trava no primeiro frame de sua direção
                frame_atual = 0;
                frame_contador = 0;
            }

        }
    



        // --- LÓGICA DE DESENHO (RENDERIZAÇÃO) ---
        if (precisa_desenhar){
            al_clear_to_color(al_map_rgb(0, 0, 0));

            // 1. Desenha o cenário de fundo
            al_draw_bitmap(cenario_fundo, 0, 0, 0);

            // --- CÁLCULO PARA al_draw_bitmap_region ---
            
            // 1. Posição de origem Y (sprite só tem uma linha, então sy é sempre 0)
            float sy = 0.0f;

            // 2. Posição de origem X (Depende do frame atual E da direção)
            // Se for ESQUERDA, precisa pular os primeiros 4 frames (4 * 16 pixels)
            float offset_x = 0.0f;
            if (direcao_atual == DIREITA){
                offset_x = (float)FRAMES_POR_DIRECAO * FRAME_LARGURA; // 4 * 16 = 64 pixels
            }

            // O ponto de partida X é o offset (se for ESQUERDA) mais o frame atual * largura do frame
            float sx = offset_x + (float)frame_atual * FRAME_LARGURA;

            // Larura e Altura da REGIÃO a ser cortada
            float sw = FRAME_LARGURA;
            float sh = FRAME_ALTURA;

            // --- DESENHO DO SPRITE ---
            al_draw_bitmap_region(
                personagem_sprite, 
                sx, sy,
                sw, sh, 
                player_x - (FRAME_LARGURA / 2.0f), // X centralizado
                player_y - (FRAME_ALTURA / 2.0f),  // Y centralizado
                0
            );

            // --- Desenho do Cronômetro ---

            // Converte o tempo total em minutos e segundos
            int minutos = (int)floor(tempo_total / 60.0);
            int segundos = (int)floor(fmod(tempo_total, 60.0));

            // Formata a string (ex: "05:30")
            char tempo_string[10];
            sprintf(tempo_string, "%02d:%02d", minutos, segundos);

            // Define a cor (branco)
            ALLEGRO_COLOR cor_tempo = al_map_rgb(255, 255, 255);

            // Posição para o canto superior direito
            float x_pos = LARGURA - 20;
            float y_pos = 10;

            // Desenha o texto
            al_draw_text(
                font,
                cor_tempo,
                x_pos, y_pos,
                ALLEGRO_ALIGN_RIGHT,
                tempo_string
            );

            // 3. Manda desenhar tudo o que foi preparado na tela
            al_flip_display();
            precisa_desenhar = false; // O desenho foi feito, agora espera a proxima atualização
        }
    }


    // ------------------------------------------
    // 4. LIMPEZA (DESTRUIÇÃO DE RECURSOS)
    // ------------------------------------------
    al_destroy_timer(timer);
    al_destroy_bitmap(cenario_fundo);
    al_destroy_bitmap(personagem_sprite);
    al_destroy_font(font);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(display);
    
    return 0;
} 