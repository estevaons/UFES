#ifndef fila_h
#define fila_h

#include"aluno.h"

typedef struct fila Fila;


Fila* iniciaFila();

void insereNaFila(Fila* fila, Aluno* al);

Aluno* retiraDaFila(Fila* fila);

void imprimeFila(Fila* fila);

void liberaFila(Fila* fila);

#endif