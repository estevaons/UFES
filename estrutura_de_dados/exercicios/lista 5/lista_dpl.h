#ifndef lista_dpl_h
#define lista_dpl_h

#include<stdio.h>
#include"item.h"

typedef struct lista ListaD;


ListaD* iniciaLista(void);

ListaD* insereNaLista(ListaD* lista, Item* item);

ListaD* retiraDaLista(ListaD* lista, char* nome);

void imprimeLista(ListaD* lista);

void destroiLista(ListaD* lista);

#endif