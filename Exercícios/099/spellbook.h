#ifndef SPELLBOOK_H
#define SPELLBOOK_H

// Struct básica do feitiço
typedef struct {
    int id;
    char name[50];
    int mana_cost;
} Spell;

// Nó da lista encadeada
typedef struct node {
    Spell spell;
    struct node* next;
} Node;

// Struct do grimório (lista)
typedef struct {
    Node* start;
} Spellbook;

// Protótipos das funções do módulo
Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif
