#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"

#define TAM 100

struct indices{
    int topo;
    int base;
};

struct pilhaD{
    Aluno* alunos[TAM];
    IndicePilha pilha1,pilha2;
};

PilhaDupla* iniciaPilhaDupla(){
    PilhaDupla* p = (PilhaDupla*)malloc(sizeof(PilhaDupla));
    p->pilha1.base = 0;
    p->pilha1.topo = -1; //cresce para a direita
    p->pilha2.base = TAM -1;
    p->pilha2.topo =  TAM;

    return p;
}

void pushPilha1(PilhaDupla* p, Aluno* al){
    if(p->pilha1.topo +1 == p->pilha2.topo){
        printf("A PILHA ESTA CHEIA, ALUNO NAO PODE SER INSERIDO\n");
    }else{
        p->pilha1.topo = p->pilha1.topo+1;
        p->alunos[p->pilha1.topo] = al;
    }
}

void pushPilha2(PilhaDupla* p, Aluno* al){
    if(p->pilha1.topo +1 == p->pilha2.topo){
        printf("A PILHA ESTA CHEIA, ALUNO NAO PODE SER INSERIDO\n");
    }else{
        p->pilha2.topo = p->pilha2.topo -1;
        p->alunos[p->pilha2.topo] = al;

        // printf("%d\n",p->pilha2.topo);
        // imprimeAluno(p->alunos[p->pilha2.topo]);
    }
}

Aluno* popPilha1(PilhaDupla* p){
    if(p->pilha1.topo == -1){
        printf("Pilha vazia!!!\n");
        return NULL;
    }
    Aluno* al = p->alunos[p->pilha1.topo];
    p->pilha1.topo--;


    return al;
}

Aluno* popPilha2(PilhaDupla* p){
    if(p->pilha2.topo == TAM){
        printf("Pilha vazia!!!\n");
        return NULL;
    }
    Aluno* al = p->alunos[p->pilha2.topo];
    p->pilha2.topo = p->pilha2.topo +1;
}

void imprimePilha1(PilhaDupla* p){
    int i;
      
    if(!p){
    
        return;
    }
    for(i=(p->pilha1.topo); i>=0 ;i--){ 
        imprimeAluno(p->alunos[i]);
    }
      
}

void imprimePilha2(PilhaDupla* p){
    int i;

    if(!p){
        return;
    }
    for(i=(p->pilha2.topo);i<TAM;i++){
        imprimeAluno(p->alunos[i]);
    }
}

void libera(PilhaDupla* p){
    if(!p){
        return;
    }
    free(p);
}

