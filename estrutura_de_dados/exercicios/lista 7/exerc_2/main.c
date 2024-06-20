#include<stdio.h>
#include<stdlib.h>
#include"pilhaMult.h"


int main(){


    Aluno* al1 = iniciaAluno("miguel",321,6.7);
    Aluno* al2 = iniciaAluno("joana",31321,5.3);
    Aluno* al3 = iniciaAluno("joao",43242,4.2);
    Aluno* al4 = iniciaAluno("pedro",54353,6.9);
    Aluno* al5 = iniciaAluno("penha",6546,8.7);
    Aluno* al6 = iniciaAluno("ana",3213,9.7);
    Aluno* al7 = iniciaAluno("wemerson",4324,2.1);
    Aluno* al8 = iniciaAluno("xenna",6546,3.4);
    Aluno* al9 = iniciaAluno("maria",3213,4.3);
    Aluno* al10 = iniciaAluno("luan",54353,5.2);

    PilhaMult* pilha = iniciaPilhaMult();

    push(pilha,al1,0);
    push(pilha,al2,0);

    printf("imprimindo pilha 0\n");
    imprimePilha(pilha,0);

    push(pilha,pop(pilha,0),1);
    push(pilha,pop(pilha,0),1);

    printf("-----------\n");
    printf("imprimindo pilha 1\n");
    imprimePilha(pilha,1);

    push(pilha,al3,2);
    push(pilha,al4,2);

    printf("-----------\n");
    printf("imprimindo pilha 2\n");
    imprimePilha(pilha,2);


    push(pilha,pop(pilha,2),3);
    push(pilha,pop(pilha,2),3);

    printf("-----------\n");
    printf("imprimindo pilha 3\n");
    imprimePilha(pilha,3);


    push(pilha,al5,4);
    push(pilha,al6,4);

    printf("-----------\n");
    printf("imprimindo pilha 4\n");
    imprimePilha(pilha,4);

    push(pilha,pop(pilha,4),5);
    push(pilha,pop(pilha,4),5);

    printf("-----------\n");
    printf("imprimindo pilha 5\n");
    imprimePilha(pilha,5);    

    push(pilha,al7,6);
    push(pilha,al8,6);

    printf("-----------\n");
    printf("imprimindo pilha 6\n");
    imprimePilha(pilha,6);

    push(pilha,pop(pilha,6),7);
    push(pilha,pop(pilha,6),7);

    printf("-----------\n");
    printf("imprimindo pilha 7\n");
    imprimePilha(pilha,7);


    push(pilha,al9,8);
    push(pilha,al10,8);

    printf("-----------\n");
    printf("imprimindo pilha 8\n");
    imprimePilha(pilha,8);


    push(pilha,pop(pilha,8),9);
    push(pilha,pop(pilha,8),9);

    printf("-----------\n");
    printf("imprimindo pilha 9\n");
    imprimePilha(pilha,9);

    libera(pilha);

    liberaAluno(al1);
    liberaAluno(al2);
    liberaAluno(al3);
    liberaAluno(al4);
    liberaAluno(al5);
    liberaAluno(al6);
    liberaAluno(al7);
    liberaAluno(al8);
    liberaAluno(al9);
    liberaAluno(al10);
  




    return 0;
}