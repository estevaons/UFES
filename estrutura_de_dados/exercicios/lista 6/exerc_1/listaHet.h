#ifndef LISTAHET_H
#define LISTAHET_H
#include<stdio.h>
#include"triangulo.h"
#include"retangulo.h"
#include"circulo.h"

typedef struct listahet ListaHet;

ListaHet* iniciaLista();

void insereTriangulo(ListaHet* lista, Triangulo* tri);

void insereRetangulo(ListaHet* lista, Retangulo* ret);

void insereCirculo(ListaHet* lista, Circulo* circ);

float max_area (ListaHet* lista);

void imprimeLista(ListaHet* lista);

void destroiLista(ListaHet* lista);



#endif