
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

struct posicao{
    int linha;
    int coluna;
    double valor;
};

Lista* Inicia(){
    Lista *a;

    a = (Lista*)malloc(sizeof(Lista));
    a->pt_valor = (Posicao*)malloc(sizeof(Posicao));

    return a;
}

void Printa(Lista *el){
    int i = 1;
    if(el){
        printf("Posicao\n");
        while(el){
            printf("Elemento %d:\n", i);
            printf("Linha: %d\n", el->pt_valor->linha);
            printf("Coluna: %d\n", el->pt_valor->coluna);
            printf("Valor: %lf\n", el->pt_valor->valor);
            el = el->prox;
            i++;
        }
    }else{
        printf("Lista vazia");
    }
}



void Desaloca(Lista* el){
    free(el->pt_valor);
    free(el);
}


void Preenche(Lista* l){
    printf("Indique a linha e a coluna do valor: \n");
    scanf("%d %d", &l->pt_valor->linha, &l->pt_valor->coluna);
    printf("Indique o valor:\n");
    scanf("%lf", &l->pt_valor->valor);
}