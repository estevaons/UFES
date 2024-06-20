#ifndef listaMat_h
#define listaMat_h
#include"matriz.h"

typedef struct listaDeMat ListaDeMatrizes;

ListaDeMatrizes* iniciaListaDeMatrizes();

void insereListaMat(ListaDeMatrizes* lista, Matriz* mat);

Matriz* removeMatrizDaLista(ListaDeMatrizes* lista, Matriz* mat);

void imprimeListaMat(ListaDeMatrizes* lista);

void liberaListaMat(ListaDeMatrizes* lista);


#endif