#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* cabeca; // Nó de cabeçalho
} Lista;

Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void imprimirLista(Lista* lista);
int remover(Lista* lista, int valor);
void liberarLista(Lista* lista);
void reverterLista(Lista* lista);

#endif