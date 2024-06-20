#ifndef KERNER_H_
#define KERNER_H_

struct Complexo{
    double re;
    double im;
};
typedef struct Complexo tComplexo;

void Kremer(tComplexo coeficientes[], int grau);
tComplexo ProdutoComplexos(tComplexo p, tComplexo q);
tComplexo Denominador(tComplexo raizes[], int grau, int i);
tComplexo Power(int i);
tComplexo SomaComplexos(tComplexo p, tComplexo q);
tComplexo DivisaoComplexos(tComplexo p, tComplexo q);
tComplexo SubtracaoComplexos(tComplexo p, tComplexo q);
tComplexo polinomio (tComplexo coeficientes[], tComplexo x, int grau);
#endif