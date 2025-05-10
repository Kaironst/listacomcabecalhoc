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

void inserirFim(Lista* lista, int valor) {
    No* aux;
    for(aux=lista->cabeca->prox;aux->prox!=NULL;aux=aux->prox); //marca aux como o ultimo nó da lista
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox=aux->prox;
    aux->prox=novo; //insere o valor entre o final e NULL
}

int contarElementos(Lista* lista) {
    No* aux;
    int num=0;
    for(aux=lista->cabeca;aux->prox!=NULL;aux=aux->prox) num++; //percorre a lista e incrementa num pra cada pulo feito
    return num;
}

int buscar(Lista* lista, int valor) {
    No* aux;
    for(aux=lista->cabeca->prox;aux!=NULL;aux=aux->prox) if (aux->dado==valor) return 1;
    return 0;
} 

void reverterLista(Lista* lista) {
    if(estaVazia(lista)) return;
    
    No* noFinal = lista->cabeca;
    No* anteriorInicio = lista->cabeca;
    No* noInicial = lista->cabeca->prox;
    No* iniciodatroca=lista->cabeca->prox;
    No* aux;
    
    for(;;) {
        for(;noFinal->prox->prox!=NULL;noFinal=noFinal->prox); //marca noFinal como o ultimo valor da lista
        aux=noFinal;
        noFinal=noFinal->prox;
        if (noFinal==noInicial) break;
        aux->prox=noFinal->prox;  //essas linhas depois do for todas serverm para garantir q o null fique no final
        

        anteriorInicio->prox=noFinal;
        noFinal->prox=noInicial; //inverte os valores finais e iniciais* (o inicial não muda por que ele fica na posição correta ao final da troca)
    
        anteriorInicio=noFinal;
    }
    
    
}

int obterMaior(Lista* lista) {
    if (estaVazia(lista)) {
        printf("A lista está vazia.\n");
        return -1;
    }
    No* aux;
    int valor=lista->cabeca->prox->dado;
    for(aux=lista->cabeca->prox;aux!=NULL;aux=aux->prox) if (aux->dado>valor) valor=aux->dado; //percorre todos os valores e retorna o maior
    return valor;
}

int obterMenor(Lista* lista) {
    if (estaVazia(lista)) {
        printf("A lista está vazia.\n");
        return -1;
    }
    No* aux;
    int valor=lista->cabeca->prox->dado; //valor inicia como o primeiro valor da lista
    for(aux=lista->cabeca->prox;aux!=NULL;aux=aux->prox) if (aux->dado<valor) valor=aux->dado; //percorre todos os valores e retorna o maior
    return valor;
}

int estaVazia(Lista* lista) {
    return (lista->cabeca->prox==NULL);
}

Lista* copiarLista(Lista* lista) {
    Lista* lista2 = (Lista*)malloc(sizeof(Lista));
    lista2->cabeca = (No*)malloc(sizeof(No));  //declara a lista e seu cabeçalho
    No* aux;
    No* aux2=lista2->cabeca;

    for(aux=lista->cabeca->prox;aux!=NULL;aux=aux->prox) {
        aux2->prox = (No*)malloc(sizeof(No));
        aux2=aux2->prox;
        aux2->dado=aux->dado;
    } //cria um novo no na na proxima localização da nova lista e copia o valor
    aux2->prox=NULL;  //coloca NULL no fim da nova lista para manter sua integridade
    return lista2;

}

void concatenarListas(Lista* l1, Lista* l2) {
    No* aux; for(aux=l1->cabeca->prox;aux->prox!=NULL;aux=aux->prox); //marca aux como o ultimo elemento da lista 1
    No* aux2;

    for (aux2=l2->cabeca->prox;aux2!=NULL;aux2=aux2->prox) {
        aux->prox = (No*)malloc(sizeof(No));
        aux=aux->prox;
        aux->dado=aux2->dado;
    }
    aux->prox=NULL;  //mesmo processo que na função anterior mas a cópia é direcionada ao final da primeira lista
}