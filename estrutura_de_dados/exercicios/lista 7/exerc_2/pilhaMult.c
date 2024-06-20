#include<stdio.h>
#include<stdlib.h>
#include"pilhaMult.h"

#define MaxTam 100
#define N 10

struct indice{
    int topo,base;
};

struct pilhaM{
    Aluno* alunos[MaxTam];
    IndicePilha pilha[N];
};

PilhaMult* iniciaPilhaMult(){
    PilhaMult*p = (PilhaMult*)malloc(sizeof(PilhaMult));
    int cont =0;

    for(int i=0;i<N;i++){
        p->pilha[i].base = 0+cont;
        p->pilha[i].topo = -1+cont;
        cont += MaxTam/N;
    }
    return p ;
}

void push(PilhaMult* p, Aluno* al, int numPilha){

    if(numPilha == N-1 && p->pilha[numPilha].topo != MaxTam -1){
        p->pilha[numPilha].topo = p->pilha[numPilha].topo+1;
        p->alunos[p->pilha[numPilha].topo] = al;
    }

    else if(p->pilha[numPilha].topo +1 == p->pilha[numPilha+1].base ){
        printf("pilha vazia!!!\n");
    }else{
        p->pilha[numPilha].topo = p->pilha[numPilha].topo+1;
        p->alunos[p->pilha[numPilha].topo] = al;
    }

    

}

Aluno* pop(PilhaMult* p, int numPilha){

   

    if(p->pilha[numPilha].topo == p->pilha[numPilha].base -1){
        printf("lista vazia!!!\n");
    }
    Aluno* al = p->alunos[p->pilha[numPilha].topo];
    p->pilha[numPilha].topo--;

    return al;
}

void imprimePilha(PilhaMult*p, int numPilha){

  

    if(p->pilha[numPilha].topo == p->pilha[numPilha].base -1){
        printf("lista vazia!!!\n");
    }
    if(!p){
        return;
    }
    for(int i= p->pilha[numPilha].topo; i>=p->pilha[numPilha].base;i--){
        imprimeAluno(p->alunos[i]);
    }
}

void libera(PilhaMult* p){
    if(!p){
        return;
    }
    free(p);
}