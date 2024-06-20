#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bool.h"

bool* init_bool(int n){
    
        bool *v = (bool*)malloc(n * sizeof(bool));
    
        for(int i = 2 ; i < n ; i++){
            v[i] = true;
        }
    
        return v;
}

void mark_bool(bool *v, int n){
    for(int i = 2 ; i < n ; i++){
        if(v[i] == true){
            for(int j = i + 1 ; j < n ; j++){
                if(j % i == 0){
                    v[j] = false;
                }
            }
        }
    }
}

void print_bool(bool *v, int n){
    for(int i = 2 ; i < n ; i++){
        if(v[i] == true){
            printf("%d ", i);
        }
    }
}

void free_bool(bool *v){
    free(v);
}