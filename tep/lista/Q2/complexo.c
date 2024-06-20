//
// Created by estevaons on 07/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#ifdef TYPE
#ifdef TYPED


void TYPED(CrieNumeroComplexo)(TYPED(tComplexo) **pointer){
    *pointer = malloc(sizeof (TYPED(tComplexo)));
}

// void TYPED(CrieVetorComplexo)(TYPED(tComplexo) **vet, unsigned  int tamanho){
//     *vet = (tComplexo *)malloc(tamanho* sizeof (tComplexo));
// }

void TYPED(PreencheComplexoDeReais)(TYPED(tComplexo) * pointer, TYPE num1, TYPE num2){
    pointer->num1 = num1;
    pointer->num2 = num2;
}

TYPED(tComplexo) TYPED(SomaComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q){
    TYPED(tComplexo) soma;
    soma.num1 = p->num1 + q->num1;
    soma.num2 = p->num2 + q->num2;

    return soma;
}

TYPED (tComplexo) TYPED(ProdutoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q){
    TYPED(tComplexo) resultado;
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

TYPED(tComplexo) TYPED(SubtracaoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q){
    TYPED(tComplexo) resultado;

    resultado.num1 = p->num1 - q->num2;
    resultado.num2 = p->num2 - q->num2;


    return resultado;
}

TYPED(tComplexo) TYPED(DivisaoComplexos)(TYPED(tComplexo) *p, TYPED(tComplexo) *q){
    TYPED(tComplexo) resultado;
    resultado.num1 = (((p->num1*q->num1) + (p->num2*q->num2))/(q->num1*q->num1 + q->num2*q->num2));
    resultado.num2 = ((-(p->num1*q->num2) + (p->num2*q->num1))/(q->num1*q->num1 + q->num2*q->num2));

    return resultado;
}

void TYPED(ApresentaComplexo)(TYPED(tComplexo) opr){
    char cmd[20];
    strcpy(cmd,"");
    strcat(cmd, " %");
    strcat(cmd, TIPO);
    if(opr.num2 >= 0){
        strcat(cmd, " + ");
    }
    strcat(cmd, "%");
    strcat(cmd, TIPO);
    strcat(cmd, "i");

    printf(cmd, opr.num1, opr.num2);
    printf("\n");


}

void TYPED(DesalocaMemoria)(TYPED(tComplexo) *pointer){
    free(pointer);
}

 #endif
 #endif