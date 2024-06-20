#include<stdio.h>
#include"listaHet.h"
#include<stdlib.h>

#define TRI 0
#define RET 1
#define CIRC 2

typedef struct cel Celula;

struct cel{
    Celula* prox;
    void* item;
    int tipo;
};

struct listahet{
    Celula* prim;
    Celula* ult;
};

ListaHet* iniciaLista(){
    ListaHet* lista = (ListaHet*)malloc(sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereTriangulo(ListaHet* lista, Triangulo* tri){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = tri;
    nova->tipo = TRI;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void insereRetangulo(ListaHet* lista, Retangulo* ret){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = ret;
    nova->tipo = RET;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }    
}

void insereCirculo(ListaHet* lista, Circulo* circ){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = circ;
    nova->tipo = CIRC;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }       
}

void imprimeLista(ListaHet* lista){
    Celula* aux;

    for(aux = lista->prim; aux!=NULL; aux = aux->prox){
        if(aux->tipo == TRI){
            imprimeTriangulo((Triangulo*)aux->item);
        }
        if(aux->tipo == RET){
            imprimeRetangulo((Retangulo*)aux->item);
        }
        if(aux->tipo == CIRC){
            imprimeCirculo((Circulo*)aux->item);
        }
    }
}


void destroiLista(ListaHet* lista){
    Celula* aux = lista->prim;
    Celula* temp;

    while(aux != NULL){
        temp = aux->prox;
        free(aux);
        aux = temp;
    }

    free(lista);
}

float max_area (ListaHet* lista){
    float amax = 0;
    float a = 0;

    Celula* aux;

    for(aux = lista->prim; aux!=NULL; aux= aux->prox){
        if(aux->tipo == TRI){
            a = calculaAreaTriangulo(aux->item);
        }
        if(aux->tipo == RET){
            a = calculaAreaRetangulo(aux->item);
        }
        if(aux->tipo == CIRC){
            a = calculaAreaCirculo(aux->item);
        }

        if(a>=amax){
            amax = a;
        }
    }

    return amax;
}
