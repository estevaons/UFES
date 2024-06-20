#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


Prim_noh* CriaPonteiro(){
    Prim_noh *at;
    at = (Prim_noh*)malloc(sizeof(Prim_noh));

    return at;
}

void setaValor(Prim_noh *p, void *n){
    p->pt_valor = n;
}


void Printa(Prim_noh *p){
    if(p){
        while(p){
            printf("%d\n", (*(int*)p->pt_valor));
            p=p->prox;
        }
    }else{
        printf("Lista vazia");
    }
}



void Desaloca(Prim_noh *p){
    free(p->pt_valor);
    free(p);
}