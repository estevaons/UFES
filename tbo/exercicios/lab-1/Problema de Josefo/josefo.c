#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "josefo.h"

//inicializa vetor de booleano
bool* init_bool(int n){
    bool *v = (bool*)malloc(n * sizeof(bool));

    for(int i = 1 ; i <= n ; i++){
        v[i] = true;
    }

    return v;
}

//inicializa vetor auxiliar
int* init_int(int n){
    
        int *v = (int*)malloc(n * sizeof(int));
    
        for(int i = 0; i < n-1 ; i++){
            v[i] = 0;
        }
    
        return v;
}

//marca os eliminados no vetor de booleano e armazena a ordem de eliminação no vetor auxiliar
void josefo(bool *v, int n, int m, int* v_aux){
    int i = 1;
    int j = 0;
    int cont = 0;
    while(cont < n){
        if(v[i] == true){
            j++;
            if(j == m){
                v[i] = false;
                v_aux[cont] = i;
                j = 0;
                cont++;
            }
        }
        i++;
        if(i > n){
            i = 1;
        }
    }
}

//imprimi o vetor de booleano
void print_bool(bool *v, int n){
    for(int i = 0 ; i < n ; i++){
        if(v[i] == true){
            printf("%d ", i);
        }
    }
}

//imprimi o vetor auxiliar
void print_int(int *v, int n){
    for(int i = 0 ; i < n-1 ; i++){
        printf("%d ", v[i]);
    }
}

//libera o vetor de booleano
void free_bool(bool *v){
    free(v);
}

//libera o vetor auxiliar
void free_int(int *v){
    free(v);
}