#include <stdio.h>
#include <stdlib.h>
#include "w_quick_union.h"

void init_vector_wq(int* vet, int*size, int n){
    for(int i=0; i<n; i++){
        vet[i] = i;
        size[i] = 1;
    }
}

int find_wq(int* vet, int i){
    while(i != vet[i]){
        vet[i] = vet[vet[i]];
        i = vet[i];
    }
    return i;
}


void union_wq(int* vet, int *size, int p, int q){
    int i = find_wq(vet,p);
    int j = find_wq(vet,q);

    if(i == j){
        return;
    }

   if (size[i] < size[j]){
        vet[i] = j; size[j] += size[i];
   }else{
        vet[j] = i; size[i] += size[j];
   }
}


int connected_wq(int* vet, int p, int q){
    return find_wq(vet,p) == find_wq(vet,q);
}