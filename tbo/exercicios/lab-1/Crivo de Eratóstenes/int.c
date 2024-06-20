#include <stdio.h>
#include <stdlib.h>
#include "int.h"

int* init_int(int n){

    int *v = (int*)malloc(n * sizeof(int));

    for(int i = 2 ; i < n ; i++){
        v[i] = i;
    }

    return v;
}

void mark_int(int *v, int n){
    for(int i = 2 ; i < n ; i++){
        if(v[i] != 0){
            for(int j = i + 1 ; j < n ; j++){
                if(v[j] % v[i] == 0){
                    v[j] = 0;
                }
            }
        }
    }
}

void print_int(int *v, int n){
    for(int i = 2 ; i < n ; i++){
        if(v[i] != 0){
            printf("%d ", v[i]);
        }
    }
}

void free_int(int *v){
    free(v);
}