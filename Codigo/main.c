#include <stdio.h>
#include "cafeteria.h"
#include "logica.c"
int main() {
    Item *cardapio = NULL;
    
    // 1. Teste de Adição
    cardapio = adicionarAoCardapio(cardapio, 1, "Cafe", 5.0);
    cardapio = adicionarAoCardapio(cardapio, 2, "Bolo", 10.0);
    
    // 2. Listagem Inicial
    listarCardapio(cardapio);

    // 3. Teste de Edição
    printf("\nEditando o item 1...\n");
    editarItem(cardapio, 1);
    
    // 4. Teste de Remoção
    printf("\nRemovendo o item 2...\n");
    cardapio = deletarItem(cardapio, 2);

    // 5. Resultado Final
    listarCardapio(cardapio);

    return 0;
}

