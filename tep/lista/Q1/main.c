#include <stdio.h>
#include "complexo.h"
int main (){
    tComplexo *p, *q,
            vet1[10], *vet2,
            soma, produto, divisao, subtracao,
            produtorio, somatorio;

    unsigned int i;
    long double modulo;

    CrieNumeroComplexo (&p);
    CrieNumeroComplexo (&q);
    CrieVetorComplexo (&vet2, 10);

    PreencheComplexoDeReais (p, 1.0 , 2.0);
    PreencheComplexoDeReais (q, 3.0 , 4.0);

    soma = SomaComplexos (p, q);
    produto = ProdutoComplexos (p,q);
    subtracao = SubtracaoComplexos (p,q);
    divisao = DivisaoComplexos (p,q);
    modulo = ModuloComplexo (p);
    for (i = 0; i < 10; i++){
        PreencheComplexoDeReais (&(vet1[i]), (double)i , (double)i);
        PreencheComplexoDeReais (&(vet2[i]), (double)i , (double)i);
    }

    produtorio = ProdutoInternoVetComplexo (vet1, vet2, 10);
    somatorio = SomaElementosVetComplexo (vet1, 10);

    ApresentaComplexo (soma, "p + q = ");
    ApresentaComplexo (produto, "p * q = ");
    ApresentaComplexo (divisao, "p / q = ");
    ApresentaComplexo (subtracao, "p + q = ");
    ApresentaComplexo (produtorio, "vet1 . vet2 = ");
    ApresentaComplexo (somatorio, "soma elementos de vet1 = ");
    printf ("O modulo de p eh %Lf\n", modulo);
    DesalocaMemoria(p);
    DesalocaMemoria(q);
    DesalocaMemoria(vet2);
}