#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

#define TamVet 10

struct fila {
    int inicio;
    int num;
    Aluno* alunos[TamVet];
};

Fila* iniciaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = 0;
    fila->num = 0;

    return fila;
}

void insereNaFila(Fila* fila, Aluno* al){
    if(!fila || fila->num >= TamVet){
        printf("Fila cheia ou invalida!\n");
        return;
    }
    int aux = (fila->inicio + fila->num)%TamVet;
    fila->alunos[aux] = al;
    fila->num++;
}

Aluno* retiraDaFila(Fila* fila){
    if(!fila || fila->num == 0){
        printf("Fila vazia ou invalida!\n");
        return NULL;
    }
    Aluno* al = fila->alunos[fila->inicio];
    fila->inicio = (fila->inicio+1)%TamVet;

    fila->num--;

    return al;
}

void imprimeFila(Fila* fila){
    int aux = 0;

    if(!fila){
        return;
    }

    for(int i=0; i<fila->num; i++){
        aux = (fila->inicio+i)%TamVet;
        imprimeAluno(fila->alunos[aux]);
    }

}

void liberaFila(Fila* fila){
    if(!fila){
        return;
    }

    free(fila);
}