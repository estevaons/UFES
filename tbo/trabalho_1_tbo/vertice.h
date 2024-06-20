#ifndef VERTICE_H_
#define VERTICE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <unistd.h>

struct vertice{
    char* id;
    float* coords;
};

typedef struct vertice Vertice;

int read_file(Vertice*** v,int dimension, FILE* entrada);

int comparaVertices(const void* a, const void* b);

Vertice* criaVertice(int dimension, char* id);

void liberaVertices(Vertice** v, int num_vertices);

#endif