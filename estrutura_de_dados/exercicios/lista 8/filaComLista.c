#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#include"lista.h"

struct fila {
    Lista* lista;
};

Fila* iniciaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->lista = iniciaLista();

    return fila;
}

void insereNaFila(Fila* fila, Aluno* al){
    insereNaListaUlt(fila->lista,al);
}


Aluno* retiraDaFila(Fila* fila){
    return retiraDaPrimeiraPosLista(fila->lista);
}


void imprimeFila(Fila* fila){
    imprimeLista(fila->lista);
}

void liberaFila(Fila* fila){
    liberaLista(fila->lista);
    free(fila);
}