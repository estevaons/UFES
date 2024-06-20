#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"lista.h"

typedef struct cel Celula;

struct cel{
    Aluno* aluno;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* iniciaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereNaLista(Lista* lista, Aluno* al){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->aluno = al;

    nova->prox = lista->prim;

    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void insereNaListaUlt(Lista* lista, Aluno* al){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->aluno = al;
    nova->prox = NULL;

    if(lista->ult == NULL){
        lista->prim = lista->ult = nova;
        return;
    }
    lista->ult->prox = nova;
    lista->ult = nova;

}

void imprimeLista(Lista* lista){
    Celula* aux;

    for(aux = lista->prim; aux!=NULL; aux = aux->prox){
        imprimeAluno(aux->aluno);
    }
}

Aluno* retiraDaPrimeiraPosLista(Lista* lista){
    Aluno* al;
    Celula* aux = lista->prim;

    if(lista->prim == NULL){// lista vazia
        return NULL;
    }

    al = lista->prim->aluno;

    
    lista->prim = lista->prim->prox;

    free(aux);

    return al;
}


Aluno* retiraDaLista(Lista* lista, char* nome){
    Celula* aux = lista->prim;
    Aluno* al;

    Celula* ant = NULL;


    while(aux != NULL && strcmp(retornaNomeAluno(aux->aluno),nome)){
        ant = aux;
        aux = aux->prox;
    }


    if(aux == NULL){
        return NULL;
    }

    al = aux->aluno;

    if(aux == lista->prim && aux == lista->ult){
        lista->prim = lista->ult = NULL;
    }
    else if(aux == lista->prim){
        lista->prim = aux->prox;
    }
    else if(aux == lista->ult){
        lista->ult = ant;
        lista->ult->prox = NULL;
    }else{
        ant->prox = aux->prox;
    }

    free(aux);

    return al;


}



void liberaLista(Lista* lista){
    Celula* aux = lista->prim;
    Celula* temp;

    while(aux != NULL){
        temp = aux->prox;
        free(aux);
        aux = temp;
    }
    free(lista);
}