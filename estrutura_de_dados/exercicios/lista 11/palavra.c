#include "palavra.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

struct palavra{
    char* string;
    int num;
    struct palavra* prox;
};

Palavra* inicia_palavra(char* str){
    Palavra* palavra = (Palavra*)malloc(sizeof(Palavra));
    palavra->string = strdup(str);
    palavra->num = 0;
    palavra->prox = NULL;
    return palavra;
}

char* retornaString(Palavra* palavra){
    return palavra->string;
}

void atualizaOcorrencias(Palavra* palavra){
    palavra->num++;
}

int retornaOcorrencias(Palavra* palavra){
    return palavra->num;
}

Palavra* buscaPalavra(Palavra* palavra, char* str){
    Palavra* p;
    for(p = palavra; p!=NULL; p = p->prox){
        if(strcmp(str,p->string)== 0){
            return p;
        }
    }
    return NULL;
}

Palavra* inserePalavraNaLista(Palavra* lista, Palavra* palavra){
    palavra->prox = lista;
    return palavra;
}

int contaPalavrasNaLista(Palavra* palavra){
    Palavra* p;
    int i = 0;
    for(p = palavra; p!=NULL; p = p->prox){
        i++;
    }
    return i;
}

void imprimeLista(Palavra* palavra){
    Palavra* p;

    for(p = palavra; p!=NULL; p=p->prox){
        printf("String: %s - Ocorrencia: %d\n",p->string,p->num);
    }
}

void liberaListaDePalavra(Palavra* palavra){
    Palavra* p = palavra;
    Palavra* t;

    while(p != NULL){
        t = p->prox;
        free(p->string);
        free(p);
        p = t;
    }
}