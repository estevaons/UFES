#include "hash.h"
#include "palavra.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>


struct hash{
    Palavra** vetor;
    int tam;
};

static int hash (char* string, int tam){
    int i;
    int total = 0;
    for(i=0; string[i]!='\0';i++){
        total += string[i];
    }
    return (total % tam);
}

Hash* inicia_Hash(int tam){
    int i;

    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->tam = tam;

    h->vetor = (Palavra**)malloc(tam*sizeof(Palavra*));

    for(i=0; i<tam; i++){
        h->vetor[i] = NULL;
    }
    return h;
}

Palavra* acessa(Hash* h, char* string){
    Palavra* p;

    int indice = hash(string, h->tam);

    p = buscaPalavra(h->vetor[indice],string);

    if(p){
        return p;
    }

    p = inicia_palavra(string);

    h->vetor[indice] = inserePalavraNaLista(h->vetor[indice], p);

    return p;
}

void imprimeHash(Hash* h){
    int i;

    for(i=0;i<h->tam;i++){
        printf("\nPosição vet[%d]: \n ",i);
        imprimeLista(h->vetor[i]);
    }
}

void liberaHash(Hash* h){
    int i;

    for(i=0;i<h->tam; i++){
        liberaListaDePalavra(h->vetor[i]);
    }

    free(h->vetor);
    free(h);
}