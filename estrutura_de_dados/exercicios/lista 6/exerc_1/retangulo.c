#include<stdio.h>
#include"retangulo.h"
#include<stdlib.h>

struct ret{
    float base;
    float altura;
};


Retangulo* criaRetangulo(float base,float altura){
    Retangulo* ret = (Retangulo*)malloc(sizeof(Retangulo));
    ret->base = base;
    ret->altura = altura;

    return ret;
}

float calculaAreaRetangulo(Retangulo* ret){
    return ret->altura * ret->base;
}

void imprimeRetangulo(Retangulo* ret){
    printf("Retangulo de base: %.2f e altura: %.2f tem area de: %.2f\n",ret->base,ret->altura,calculaAreaRetangulo(ret));
}

void destroiRetangulo(Retangulo* ret){
    free(ret);
}