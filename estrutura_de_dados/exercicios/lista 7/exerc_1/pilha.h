#ifndef pilha_h
#define pilha_h

#include<stdio.h>
#include"aluno.h"

typedef struct indices IndicePilha;
typedef struct pilhaD PilhaDupla;

PilhaDupla* iniciaPilhaDupla();

void pushPilha1(PilhaDupla* p, Aluno* al);

void pushPilha2(PilhaDupla* p, Aluno* al);

Aluno* popPilha1(PilhaDupla* p);

Aluno* popPilha2(PilhaDupla* p);

void imprimePilha1(PilhaDupla* p);

void imprimePilha2(PilhaDupla* p);

void libera(PilhaDupla* p);

#endif