#ifndef ARESTA_H_
#define ARESTA_H_
#include "vertice.h"
#include <math.h>

struct aresta{
    double peso;
    int v1;
    int v2;
};

typedef struct aresta Aresta;

Aresta* criaAresta(int v1, int v2, float peso);

void preencheArestas(Aresta** arestas, Vertice** v, int num_vertices,int num_dimensions);

double calculaDistancia(Vertice* v1,Vertice* v2, int num_dimensions);

int comparaAresta(const void* a, const void* b);

void liberaArestas(Aresta** arestas, int num_arestas);

#endif