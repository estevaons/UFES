#include<stdio.h>
#include"arvoreBB.h"

int main(){


    Aluno* al1 = iniciaAluno("Aluno1",5,8.7);
    Aluno* al2 = iniciaAluno("Aluno2",10,4.3);
    Aluno* al3 = iniciaAluno("Aluno3",15,3.2);
    Aluno* al4 = iniciaAluno("Aluno4",20,6.5);
    Aluno* al5 = iniciaAluno("Aluno5",25,9.4);
    Aluno* al6 = iniciaAluno("Aluno6",30,7.3);

    Arvore* arvoreBB = arvoreBB_Cria();

    arvoreBB = arvoreBB_Insere(arvoreBB,al1);
    arvoreBB = arvoreBB_Insere(arvoreBB,al2);
    arvoreBB = arvoreBB_Insere(arvoreBB,al3);
    arvoreBB = arvoreBB_Insere(arvoreBB,al4);
    arvoreBB = arvoreBB_Insere(arvoreBB,al5);
    arvoreBB = arvoreBB_Insere(arvoreBB,al6);

    arvoreBB_Imprime(arvoreBB);
    printf("-----------------\n");

    arvoreBB = arvoreBB_Retira(arvoreBB,retornaMatriculaAluno(al3));
    arvoreBB = arvoreBB_Retira(arvoreBB,retornaMatriculaAluno(al5));

    arvoreBB_Imprime(arvoreBB);

    arvoreBB_Libera(arvoreBB);

    liberaAluno(al1);
    liberaAluno(al2);
    liberaAluno(al3);
    liberaAluno(al4);
    liberaAluno(al5);
    liberaAluno(al6);


    return 0;
}