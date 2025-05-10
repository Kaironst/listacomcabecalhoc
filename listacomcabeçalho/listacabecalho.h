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
void inserirFim(Lista* lista, int valor);
int contarElementos(Lista* lista);
int buscar(Lista* lista, int valor); 
void reverterLista(Lista* lista);
int obterMaior(Lista* lista);
int obterMenor(Lista* lista); 
int estaVazia(Lista* lista);
Lista* copiarLista(Lista* lista);
void concatenarListas(Lista* l1, Lista* l2);
#endif