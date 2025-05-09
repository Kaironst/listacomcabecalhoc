#include <stdio.h>

#include <stdlib.h>

#include "listacabecalho.h"

Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho
    lista->cabeca->prox = NULL;
    return lista;
}

void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int remover(Lista* lista, int valor) {
    No* ant = lista->cabeca;
    No* atual = ant->prox;
    while (atual != NULL && atual->dado != valor) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return 0; // não encontrado
    ant->prox = atual->prox;
    free(atual);
    return 1; // removido com sucesso
}

void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

void reverterLista(Lista* lista) {
    
    No* anterior = lista->cabeca->prox;
    No* atual = lista->cabeca->prox;
    No* proximo = lista->cabeca->prox;
    No* aux;

    while (atual->prox!=NULL) {
        atual=atual->prox;
    }
    proximo=atual;
    atual=atual->prox;
    aux=atual;

    do {
        proximo->prox=anterior;
        lista->cabeca->prox=atual;
        atual->prox=anterior;
        anterior=atual;

    while (atual->prox!=NULL) {
        atual=atual->prox;
    }
    proximo=atual;
    atual=atual->prox;
    aux=atual;
    } while (atual!=aux);
    
}