#ifndef W_QUICK_UNION_H
#define W_QUICK_UNION_H

#include "vertice.h"

//inicializa o vetor de ids_wq
void init_vector_wq(int* vet, int *size, int n);

//union
void union_wq(int* vet, int *size, int p, int q);

//find
int find_wq(int* vet, int i);

//verifica se p e q estao conectados
int connected_wq(int* vet, int p, int q);

#endif