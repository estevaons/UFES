#include"listaHet.h"
#include<stdlib.h>

#define ALU 0
#define PRO 1


#include<stdio.h>

typedef struct cel Celula;

struct cel {
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

void insereAluno(ListaHet* lista, Aluno* al){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = al;
    nova->tipo = ALU;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void insereProfessor(ListaHet* lista, Professor* prof){
    Celula* nova = (Celula*)malloc(sizeof(Celula));

    nova->item = prof;
    nova->tipo = PRO;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void imprimeLista(ListaHet* lista){
    Celula* aux;

    for(aux = lista->prim; aux!=NULL; aux = aux->prox){
        if(aux->tipo == PRO){
            imprimeProfessor((Professor*)aux->item);
        }
        if(aux->tipo == ALU){
            imprimeAluno((Aluno*)aux->item);
        }
    }

}

float valorChurrasco(ListaHet* lista){
    Celula* aux;
    float valor = 0;

    for(aux = lista->prim; aux!=NULL; aux = aux->prox){
        if(aux->tipo == PRO){
            valor = valor + 0.02* retornaSalarioProfessor((Professor*)aux->item);
        }
        if(aux->tipo == ALU){
            valor = valor + 30.0;
        }
    }

    return valor;
}

void liberaLista(ListaHet* lista){
    Celula* aux = lista->prim;
    Celula* temp;

    while(aux != NULL){
        temp = aux->prox;
        free(aux);
        aux = temp;
    }

    free(lista);
}