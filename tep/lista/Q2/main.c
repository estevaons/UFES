#include<stdio.h>
#include<stdlib.h>

int main(){
    #include "genericD.h"
    #include "genericL.h"

    tComplexo_D soma,produto,div,sub;
    tComplexo_D *q;
    tComplexo_D *p;

    tComplexo_Ld soma2,produto2,div2,sub2;
    tComplexo_Ld *q2;
    tComplexo_Ld *p2;

    CrieNumeroComplexo_D(&p);
    CrieNumeroComplexo_D(&q);

   PreencheComplexoDeReais_D(p, 1.0 , 2.0);
   PreencheComplexoDeReais_D(q, 3.0 , 4.0);

   soma = SomaComplexos_D (p, q);
   produto = ProdutoComplexos_D(p,q);
   sub = SubtracaoComplexos_D(p,q);
   div = DivisaoComplexos_D(p,q);

   ApresentaComplexo_D(soma);
   ApresentaComplexo_D(produto);
   ApresentaComplexo_D(sub);
   ApresentaComplexo_D(div);

   CrieNumeroComplexo_Ld(&p2);
   CrieNumeroComplexo_Ld(&q2);

   PreencheComplexoDeReais_Ld(p2, 1.0, 2.0);
   PreencheComplexoDeReais_Ld(q2, 3.0, 4.0);

   soma2 = SomaComplexos_Ld(p2,q2);
   produto2 = ProdutoComplexos_Ld(p2,q2);
   sub2 = SubtracaoComplexos_Ld(p2,q2);
   div2 = DivisaoComplexos_Ld (p2,q2);

   ApresentaComplexo_Ld(soma2);
   ApresentaComplexo_Ld(produto2);
   ApresentaComplexo_Ld(sub2);
   ApresentaComplexo_Ld(div2);

   DesalocaMemoria_D(p);
   DesalocaMemoria_D(q);
   DesalocaMemoria_Ld(p2);
   DesalocaMemoria_Ld(q2);

    return 0;
}