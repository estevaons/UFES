#ifndef lista_h
#define lista_h
#include"aluno.h"


typedef struct lista Lista;

Lista* iniciaLista();

void insereNaLista(Lista* lista, Aluno* al);

void insereNaListaUlt(Lista* lista, Aluno* al);

void imprimeLista(Lista* lista);

Aluno* retiraDaLista(Lista* lista, char* nome);

Aluno* retiraDaPrimeiraPosLista(Lista* lista);

void liberaLista(Lista* lista);

#endif