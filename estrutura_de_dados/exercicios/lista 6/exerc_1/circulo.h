#ifndef CIRCULO_H
#define CIRCULO_H


typedef struct circ Circulo;

Circulo* criaCirculo(float raio);

float calculaAreaCirculo(Circulo* circ);

void imprimeCirculo(Circulo* circ);

void destroiCirculo(Circulo* circ);


#endif