#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "vertice.h"

static void swap(int i, int j, Vertice *pq, int *map) {
    exch(pq[i], pq[j]);
    map[id(pq[i])] = i;
    map[id(pq[j])] = j;
}

void fix_up(Vertice *a, int k,Vertice *pq, int *map) {
    while (k > 1 && more(a[k/2], a[k])) {
        swap(k, k/2, pq, map);
        k = k/2;
    }
}

void fix_down(Vertice *a, int sz, int k, Vertice *pq, int *map){
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && more(a[j], a[j+1])){
      j++;
    }
    if (!more(a[k], a[j])) {
      break;
    }
    swap(k, j, pq, map);
    k = j;
  }
}


void PQ_insert(Vertice v, Vertice *pq, int *map, int *N) {
    (*N)++;
    pq[*N] = v;
    map[id(v)] = *N;
    fix_up(pq, *N, pq, map);
}


Vertice PQ_delmin(Vertice *pq, int *map, int *N) {
    Vertice min = pq[1];
    swap(1, *N, pq, map);
    (*N)--;
    fix_down(pq, *N, 1, pq, map);
    return min;
}

Vertice PQ_min(Vertice *pq) {
    return pq[1];
}

void PQ_decrease_key(int id, double value, Vertice *pq, int *map) {
    int i = map[id];
    value(pq[i]) = value;
    fix_up(pq, i, pq, map);
}

bool PQ_empty(int *N) {
    return (*N) == 0;
}

int PQ_size(int *N) {
    return *N;
}

void PQ_finish(Vertice *pq, int *map) {
    free(pq);
    free(map);
}


