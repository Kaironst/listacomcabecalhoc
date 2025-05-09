#include <stdio.h>

#include "listacabecalho.h"

int main() {
    Lista* lista = criarLista();
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirInicio(lista, 30);
    printf("Lista atual: ");
    imprimirLista(lista);
    printf("Removendo 20...\n");
    remover(lista, 20);
    imprimirLista(lista);
    liberarLista(lista);
    return 0;
}