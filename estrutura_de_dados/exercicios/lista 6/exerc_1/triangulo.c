#include<stdio.h>
#include"triangulo.h"
#include<stdlib.h>


struct tri {
    float base;
    float altura;
};

Triangulo* criaTriangulo(float base,float altura){
    Triangulo* tri = (Triangulo*) malloc(sizeof(Triangulo));
    tri->base = base;
    tri->altura = altura;

    return tri;
}

float calculaAreaTriangulo(Triangulo* tri){
    return tri->base * tri->altura;
}

void imprimeTriangulo(Triangulo* tri){
    printf("triangulo com base: %.2f e altura: %.2f tem area: %.2f\n",tri->base,tri->altura,calculaAreaTriangulo(tri));
}

void destroiTriangulo(Triangulo* tri){
    free(tri);
}