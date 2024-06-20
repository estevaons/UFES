#ifndef GRAFO_H
#define GRAFO_H
#include "aresta.h"
#include "vertice.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct grafo{
    Aresta** arestas;
    Aresta*** matriz_adj;
    Att** att;
    int* vertices;
    int num_vertices;
    int num_arestas;
    int src;
    int tam_att;
    int dest;
    double velocidade;
    double tempo_total;
    double km_total;
};

typedef struct grafo Grafo;

Grafo* cria_grafo(FILE* entrada);

void atualiza_arestas(Grafo* grafo, double time);

void simula_deslocamento(Grafo* grafo, int origem, int destino);

void print_grafo(Grafo* grafo);

void libera_grafo(Grafo* grafo);

#endif