#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"


int main(){

    Aluno* al1 = iniciaAluno("Fernando",2134,9.0);
    Aluno* al2 = iniciaAluno("Junior",4325,8.0);
    Aluno* al3 = iniciaAluno("Amanda",54353,9.3);
    Aluno* al4 = iniciaAluno("Anna",32431,5.8);

    PilhaDupla* pilhaDupla = iniciaPilhaDupla();

    pushPilha1(pilhaDupla,al1);
    pushPilha1(pilhaDupla,al2);
    pushPilha1(pilhaDupla,al3);
    pushPilha1(pilhaDupla,al4);

    imprimePilha1(pilhaDupla);
    printf(" -------------- \n");



    pushPilha2(pilhaDupla,popPilha1(pilhaDupla));
    pushPilha2(pilhaDupla,popPilha1(pilhaDupla));
    pushPilha2(pilhaDupla,popPilha1(pilhaDupla));
    pushPilha2(pilhaDupla,popPilha1(pilhaDupla));

    imprimePilha2(pilhaDupla);

    liberaAluno(al1);
    liberaAluno(al2);
    liberaAluno(al3);
    liberaAluno(al4);

    libera(pilhaDupla);



    return 0;
}