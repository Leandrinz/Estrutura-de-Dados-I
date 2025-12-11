#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

// Criar grimório vazio
Spellbook* create_spellbook() {
    Spellbook* book = (Spellbook*) malloc(sizeof(Spellbook));
    book->start = NULL;
    return book;
}

// Adicionar feitiço ao final da lista
void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->spell.id = id;
    strcpy(new_node->spell.name, name);
    new_node->spell.mana_cost = mana_cost;
    new_node->next = NULL;

    if (book->start == NULL) {
        book->start = new_node;
    } else {
        Node* temp = book->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Mostrar todos os feitiços
void display_spellbook(Spellbook* book) {
    Node* temp = book->start;
    while (temp != NULL) {
        printf("ID: %d | Feitiço: %s | Custo de Mana: %d\n",
            temp->spell.id, temp->spell.name, temp->spell.mana_cost);
        temp = temp->next;
    }
}

// Liberar memória
void destroy_spellbook(Spellbook* book) {
    Node* temp = book->start;
    while (temp != NULL) {
        Node* aux = temp;
        temp = temp->next;
        free(aux);
    }
    free(book);
}
