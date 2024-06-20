#ifndef TRIANGULO_H
#define TRIANGULO_H


typedef struct tri Triangulo;

Triangulo* criaTriangulo(float base,float altura);

float calculaAreaTriangulo(Triangulo* tri);

void imprimeTriangulo(Triangulo* tri);

void destroiTriangulo(Triangulo* tri);


#endif