#include<stdio.h>
#include"circulo.h"
#include<stdlib.h>

struct circ{
    float raio;
};

Circulo* criaCirculo(float raio){
    Circulo* circ = (Circulo*)malloc(sizeof(Circulo));
    circ->raio = raio;
    return circ;
}

float calculaAreaCirculo(Circulo* circ){
    return circ->raio*3.14;
}

void imprimeCirculo(Circulo* circ){
    printf("Circulo de raio: %.2f, tem area: %.2f\n",circ->raio,calculaAreaCirculo(circ));
}

void destroiCirculo(Circulo* circ){
    free(circ);
}