#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista_dpl.h"

struct lista{
    Item* item;
    ListaD* prox;
    ListaD* ant;
};

ListaD* iniciaLista(void){
    return NULL;
}

ListaD* insereNaLista(ListaD* lista, Item* item){

    ListaD* nova =(ListaD*)malloc(sizeof(ListaD));

    nova->item = item;
    nova->ant = NULL;
    nova->prox = lista;

    if (lista != NULL){
        lista->ant = nova;
    }
    return nova;
}

static ListaD* buscaNaLista(ListaD* lista, char* nome){
    ListaD* aux;

    for(aux = lista; aux!=NULL; aux = aux->prox){
        if(strcmp(recuperaNomeItem(aux->item), nome)==0){
            return aux;
        }
    }
    return NULL;
}

ListaD* retiraDaLista(ListaD* lista, char* nome){
    ListaD* aux = buscaNaLista(lista,nome);

    if(aux==NULL){
        return NULL;
    }

    if(aux->ant != NULL){
        aux->ant->prox = aux->prox;
    }

    else{
        lista = aux->prox;
        lista->ant = NULL;
    }

    if(aux->prox != NULL){
        aux->prox->ant = aux->ant;
    }
    else{
        aux->ant->prox = NULL;
    }

    free(aux);

    return lista;
}

void imprimeLista(ListaD* lista){
    ListaD* aux;

    for(aux = lista; aux != NULL; aux = aux->prox){
        imprimeItem(aux->item);
    }
}

void destroiLista(ListaD* lista){
    ListaD* aux = lista;
    ListaD* temp;

    while(aux != NULL){
        temp = aux->prox;

        free(aux);

        aux = temp;
    }
}