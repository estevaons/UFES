#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


void Roda(){
    Prim_noh *elemento_1,*elemento_2,*elemento_3;
    int *n1, *n2, *n3;

    n1 = malloc(sizeof(int)); // aloca dinamicamente
    n2 = malloc(sizeof(int)); // aloca dinamicamente
    n3 = malloc(sizeof(int)); // aloca dinamicamente
    
    *n1 = 1;
    *n2 = 2;
    *n3 = 3;

    elemento_1 = CriaPonteiro();
    elemento_2 = CriaPonteiro();
    elemento_3 = CriaPonteiro();

    setaValor(elemento_1, n1);
    setaValor(elemento_2, n2);
    setaValor(elemento_3, n3);

    elemento_1->prox = elemento_2;
    elemento_2->prox = elemento_3;
    elemento_3->prox = NULL;

    Printa(elemento_1);
    Desaloca(elemento_1);
    Desaloca(elemento_2);
    Desaloca(elemento_3);
}


int main() {
    Roda();
    return 0;
}