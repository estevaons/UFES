#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "char.h"

//cria um vetor de char
char* init_char(int n){
    //aloca o vetor
    //tamanho n/8 pois cada char tem 8 bits
    char *v = (char *)malloc(sizeof(char) * n/8);

    //seta todos os bits para 0
    for(int i = 0; i < n/8; i++){
        v[i] = 0;
    }

    return v;
}

void mark_char(char *vet, int tam){
    //seta o bit 0 e 1 para 1
    vet[0] = vet[0] | (1<<0);
    vet[0] = vet[0] | (1<<1);

    //percorre o vetor
    for(int i = 2; i < tam; i++){
        //se o bit i for 0
        if((vet[i/8] & (1<<(i%8))) == 0){
            //percorre o vetor marcando os multiplos de i
            for(int j = i*2; j < tam; j += i){
                vet[j/8] = vet[j/8] | (1<<(j%8));
            }
        }
    }
}

void print_char(char *vet, int tam){
    //percorre o vetor
    for(int i = 0; i < tam; i++){
        //se o bit i for 0
        if((vet[i/8] & (1<<(i%8))) == 0){
            printf("%d ", i);
        }
    }
}

void free_char(char *vet){
    free(vet);
}