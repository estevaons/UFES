#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


void Roda(){
    Lista *el1, *el2, *el3;

    el1 = Inicia();
    el2 = Inicia();
    el3 = Inicia();


    Preenche(el1);
    Preenche(el2);
    Preenche(el3);

    el1->prox = el2;
    el2->prox = el3;
    el3->prox = NULL;


    Printa(el1);
    Desaloca(el1);
    Desaloca(el2);
    Desaloca(el3);
}

int main(){
    Roda();
    return 0;
}