#include <stdio.h>
#include <stdlib.h>
#include "aresta.h"



Aresta* cria_aresta(int origem, int destino, double distancia, double velocidade){
    Aresta* a = (Aresta*) malloc(sizeof(Aresta));
    a->origem = origem;
    a->destino = destino;
    a->distancia = distancia;
    a->velocidade = velocidade;
    a->time = distancia/velocidade;
    
    return a;
}

Att* cria_att(double time, int origem, int destino, double velocidade){
    Att* a = (Att*) malloc(sizeof(Att));
    a->time = time;
    a->origem = origem;
    a->destino = destino;
    a->velocidade = velocidade;
    return a;
}


