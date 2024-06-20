#ifndef listaHet_h
#define listaHet_h
#include"professor.h"
#include"aluno.h"


typedef struct listahet ListaHet;

ListaHet* iniciaLista();

void insereAluno(ListaHet* lista, Aluno* al);

void insereProfessor(ListaHet* lista, Professor* prof);

void imprimeLista(ListaHet* lista);

float valorChurrasco(ListaHet* lista);

void liberaLista(ListaHet* lista);


#endif