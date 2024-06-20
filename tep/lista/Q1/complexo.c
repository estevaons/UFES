//
// Created by estevaons on 07/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "complexo.h"


void CrieNumeroComplexo(tComplexo **pointer){
    *pointer = malloc(sizeof (tComplexo));
}

void CrieVetorComplexo(tComplexo **vet, unsigned  int tamanho){
    *vet = (tComplexo *)malloc(tamanho* sizeof (tComplexo));
}

void PreencheComplexoDeReais(tComplexo * pointer, double num1, double num2){
    pointer->num1 = num1;
    pointer->num2 = num2;
}

tComplexo SomaComplexos(tComplexo *p, tComplexo *q){
    tComplexo soma;
    soma.num1 = p->num1 + q->num1;
    soma.num2 = p->num2 + q->num2;

    return soma;
}

tComplexo ProdutoComplexos(tComplexo *p, tComplexo *q){
    tComplexo resultado;
    double num1,num2,
            num3,num4;

    num1 = p->num1 * q->num1;
    num2 = p->num1 * q->num2;
    num3 = p->num2 * q->num1;
    num4 = p->num2 * q->num2;
    num4 = num4 * (-1);
    resultado.num1 = num1+num4;
    resultado.num2 = num2+num3;

    return resultado;
}

tComplexo SubtracaoComplexos(tComplexo *p, tComplexo *q){
    tComplexo resultado;

    resultado.num1 = p->num1 - q->num2;
    resultado.num2 = p->num2 - q->num2;


    return resultado;
}

tComplexo DivisaoComplexos(tComplexo *p, tComplexo *q){
    tComplexo resultado;
    resultado.num1 = (((p->num1*q->num1) + (p->num2*q->num2))/(q->num1*q->num1 + q->num2*q->num2));
    resultado.num2 = ((-(p->num1*q->num2) + (p->num2*q->num1))/(q->num1*q->num1 + q->num2*q->num2));

    return resultado;
}

long double ModuloComplexo(tComplexo *p){
    long double resultado = 0;
    long double j = 0, k = 0;
    j = powl(p->num1, 2);
    k = powl(p->num2, 2);
    resultado = sqrtl(j+k);

    return resultado;
}
void ApresentaComplexo(tComplexo apresenta, char *string){
    printf("%s %lf + %lf * i\n", string, apresenta.num1, apresenta.num2);
}
//da uma olhada aqui
tComplexo ProdutoInternoVetComplexo(tComplexo *v1, tComplexo *v2, unsigned int tam){
    tComplexo vetor_resultado[tam];
    tComplexo resultado;
    resultado.num1 = 0;
    resultado.num2 = 0;
    double a,b,c,d;

    for (int i = 0; i < tam; i++){
        a = v1[i].num1 * v2[i].num1;
        b = v1[i].num1 * v2[i].num2; //e.g 2i
        c = v1[i].num2 * v2[i].num1; //eg 2i
        d = v1[i].num2 * v2[i].num2; //eg 2 * i**2   i**2 = -1
        d = d * (-1);
        vetor_resultado[i].num1 = a+d;
        vetor_resultado[i].num2 = b+c;
    }

    for(int i = 0; i < tam; i++){
        resultado.num1 = resultado.num1 + vetor_resultado[i].num1;
        resultado.num2 = resultado.num2 + vetor_resultado[i].num2;
    }

    return resultado;
}

tComplexo SomaElementosVetComplexo (tComplexo *vet1, unsigned int tam){
    tComplexo resultado;
    resultado.num1 = 0;
    resultado.num2 = 0;
    for(int i = 0; i < tam; i++){
        resultado.num1 = resultado.num1 + vet1[i].num1;
        resultado.num2 = resultado.num2 + vet1[i].num2;
    }

    return resultado;
}

void DesalocaMemoria(tComplexo *pointer){
    free(pointer);
}