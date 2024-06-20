#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "w_quick_union.h"
#include "aresta.h"
#include "vertice.h"


int get_dimension(FILE* entrada);

void init_ids(char **ids);

//calcula mst com kruskal
void kruskal(Aresta** arestas,int numVertices,int numArestas,int k,int* q_id,int* q_sz);

//imprime grupos
void print_groups(int numVertices,int* q_id,int k,Vertice** vertices,FILE* saida);

#endif