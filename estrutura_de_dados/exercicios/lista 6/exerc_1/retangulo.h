#ifndef RETANGULO_H
#define RETANGULO_H


typedef struct ret Retangulo;

Retangulo* criaRetangulo(float base,float altura);

float calculaAreaRetangulo(Retangulo* ret);

void imprimeRetangulo(Retangulo* ret);

void destroiRetangulo(Retangulo* ret);


#endif