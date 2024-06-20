#include<stdio.h>
#include<stdlib.h>
#include"fila.h"


int main(){

    Aluno* al1 = iniciaAluno("chaves",3214,7.6);
    Aluno* al2 = iniciaAluno("kiko",4325,6.4);
    Aluno* al3 = iniciaAluno("chiquinha",5435,3.5);
    Aluno* al4 = iniciaAluno("nhonho",4656,8.8);


    Fila* fila1 = iniciaFila();
    Fila* fila2 = iniciaFila();


    insereNaFila(fila1,al1);
    insereNaFila(fila1,al2);
    insereNaFila(fila1,al3);
    insereNaFila(fila1,al4);

    printf("PRIMEIRA FILA:\n");
    imprimeFila(fila1);

    insereNaFila(fila2,retiraDaFila(fila1));

    printf("PRIMEIRA FILA:\n");
    imprimeFila(fila1);

    printf("SEGUNDA FILA:\n");
    imprimeFila(fila2);


    insereNaFila(fila2,retiraDaFila(fila1));

    printf("PRIMEIRA FILA:\n");
    imprimeFila(fila1);

    printf("SEGUNDA FILA:\n");
    imprimeFila(fila2);

    insereNaFila(fila2,retiraDaFila(fila1));

    printf("PRIMEIRA FILA:\n");
    imprimeFila(fila1);

    printf("SEGUNDA FILA:\n");
    imprimeFila(fila2);

    insereNaFila(fila2,retiraDaFila(fila1));

    printf("PRIMEIRA FILA:\n");
    imprimeFila(fila1);

    printf("SEGUNDA FILA:\n");
    imprimeFila(fila2);
    
    liberaAluno(al1);
    liberaAluno(al2);
    liberaAluno(al3);
    liberaAluno(al4);

    liberaFila(fila1);
    liberaFila(fila2);

    return 0;
}