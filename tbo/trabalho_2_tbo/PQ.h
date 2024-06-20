#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "vertice.h"

void PQ_init(int maxN); // cria uma min PQ com capacidade maxN
void PQ_insert(Vertice v, Vertice *pq, int *map, int *N);  // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Vertice PQ_delmin(Vertice *pq, int *map, int *N);       // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(int id, double value, Vertice *pq, int *map); // Muda a prioridade do nó com identificador 'id' para 'value'
Vertice PQ_min(Vertice *pq);          // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(int *N) ;        // Retorna True se a PQ não tem elementos
int  PQ_size(int *N);         // Número de elementos na PQ
void PQ_finish(Vertice *pq, int *map);       // Libera memória

#endif
