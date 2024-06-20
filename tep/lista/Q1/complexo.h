//
// Created by estevaons on 07/12/2020.
//

#ifndef COMPLEXO_H
#define COMPLEXO_H

struct num_complexo{
    double num1;
    double num2;
};

typedef struct num_complexo tComplexo;
void CrieNumeroComplexo(tComplexo **pointer);
void CrieVetorComplexo(tComplexo **vetor, unsigned int tam);
void PreencheComplexoDeReais(tComplexo *pointer, double num1, double num2);
tComplexo SomaComplexos(tComplexo *p, tComplexo *q);
tComplexo ProdutoComplexos(tComplexo *p, tComplexo *q);
tComplexo  SubtracaoComplexos(tComplexo *p, tComplexo *q);
tComplexo  DivisaoComplexos(tComplexo *p, tComplexo *q);
long double ModuloComplexo(tComplexo *p);
void ApresentaComplexo(tComplexo op, char *string);
tComplexo ProdutoInternoVetComplexo(tComplexo *v1, tComplexo *v2, unsigned int tam);
tComplexo SomaElementosVetComplexo (tComplexo *vet1, unsigned int tam);
void DesalocaMemoria(tComplexo *pointer);



#endif
