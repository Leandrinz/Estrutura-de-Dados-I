#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook* my_book = create_spellbook();

    add_spell(my_book, 1, "Bola de Fogo", 30);
    add_spell(my_book, 2, "Cura Menor", 15);
    add_spell(my_book, 3, "Parede de Gelo", 40);

    printf("=== Grimório do Mago ===\n");
    display_spellbook(my_book);

    destroy_spellbook(my_book);

    return 0;
}
