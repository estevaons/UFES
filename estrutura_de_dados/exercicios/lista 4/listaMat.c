#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaMat.h"


typedef struct cel Celula;

struct cel{
    Matriz* mat;
    Celula* prox;
};

struct listaDeMat{
    Celula* prim;
    Celula* ult;
};


ListaDeMatrizes* iniciaListaDeMatrizes(){
    ListaDeMatrizes* lista = (ListaDeMatrizes*)malloc(sizeof(ListaDeMatrizes));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereListaMat(ListaDeMatrizes* lista, Matriz* maT){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->mat = maT;

    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

Matriz* removeMatrizDaLista(ListaDeMatrizes* lista, Matriz* maT){
    Celula* aux = lista->prim;
    Matriz* pontMatriz;
    Celula* ant = NULL;

    //faz a busca -- criar função para ver se duas matrizes sao iguas

    while(aux!= NULL && verificaMatrizIgual(aux->mat, maT)==0){
        ant = aux;

        aux = aux->prox;
    }


    //lista vazia ou não encontrou a matriz
    if(aux == NULL){
        return NULL;
    }

    pontMatriz = aux->mat;

    //se for o único

    if(aux == lista->prim && aux == lista->ult){
        lista->prim = lista->ult = NULL; // olhar aqui dnv
    }
    else if(aux == lista->prim){
        lista->prim = aux->prox;
    }
    else if(aux == lista->ult){
        lista->ult = ant;
        lista->ult->prox = NULL;
    }
    else{
        ant->prox = aux-> prox;
    }
    free(aux);

    return pontMatriz;

}

void imprimeListaMat(ListaDeMatrizes* lista){
    Celula* aux;

    for(aux=lista->prim; aux != NULL; aux = aux->prox){
        imprimeMatriz(aux->mat);
        printf("-------------------------------\n");
    }
}

void liberaListaMat(ListaDeMatrizes* lista){
    Celula* aux = lista->prim;
    Celula* temp;

    while(aux != NULL){
        temp = aux->prox;
        //destroi Matriz
        free(aux);
        aux = temp;
    }
    free(lista);
}