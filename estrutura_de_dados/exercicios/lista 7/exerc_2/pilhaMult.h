#ifndef pilhaMult_h
#define pilhaMult_h

#include<stdio.h>
#include"aluno.h"

typedef struct indice IndicePilha;
typedef struct pilhaM PilhaMult;

PilhaMult* iniciaPilhaMult();

void push(PilhaMult* p, Aluno* al, int numPilha);

Aluno* pop(PilhaMult* p, int numPilha);

void imprimePilha(PilhaMult*p, int numPilha);

void libera(PilhaMult* p);

#endif