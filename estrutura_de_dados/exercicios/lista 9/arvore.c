#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvore.h"

struct arv{
    Aluno* aluno;
    struct arv* esq;
    struct arv* dir;
};

Arvore* arvore_CriaVazia(){
    return NULL;
}

Arvore* arvore_Cria(Aluno* al,Arvore* e,Arvore* d){
    Arvore* a = (Arvore*)malloc(sizeof(Arvore));
    a->aluno = al;
    a->esq = e;
    a->dir = d;
    return a;
}

Arvore* arvore_Libera(Arvore* a){
    if(!arvore_Vazia(a)){
        arvore_Libera(a->esq);
        arvore_Libera(a->dir);
        free(a);
    }
    return NULL;
}

int arvore_Vazia(Arvore* a){
    if(a == NULL){
        return 1;
    }
    return 0;
}

void arvore_Imprime(Arvore* a){
    printf("<");
    if(!arvore_Vazia(a)){
        imprimeAluno(a->aluno);
        arvore_Imprime(a->esq);
        arvore_Imprime(a->dir);
    }
    printf(">");
}

int arvore_Ocorrencias(Arvore*a, Aluno* al){
    if(arvore_Vazia(a)){
        return 0;
    }
    if(strcmp(retornaNomeAluno(a->aluno),retornaNomeAluno(al))==0){
        return (1 + arvore_Ocorrencias(a->esq,al) + arvore_Ocorrencias(a->dir,al));
    }
    return (arvore_Ocorrencias(a->esq,al)+ arvore_Ocorrencias(a->dir,al));
}

int arvore_QtdFolhas(Arvore* a){
    if(arvore_Vazia(a->esq) && arvore_Vazia(a->dir)){
        return 1;
    }else if(!arvore_Vazia(a->esq) && arvore_Vazia(a->dir)){
        return arvore_QtdFolhas(a->esq);
    }else if(arvore_Vazia(a->esq) && !arvore_Vazia(a->dir)){
        return arvore_QtdFolhas(a->dir);
    }
    return arvore_QtdFolhas(a->esq) + arvore_QtdFolhas(a->dir);
}

int arvore_Pertence(Arvore* a, Aluno* al){
    if(arvore_Vazia(a)){
        return 0;
    }else{
        return strcmp(retornaNomeAluno(a->aluno),retornaNomeAluno(al)) == 0 ||
        arvore_Pertence(a->esq,al) ||
        arvore_Pertence(a->dir,al);
    }
}

static int maiorEntreOsDois (int a, int b){
    return (a>b) ? a : b; // retorna a se a>b ou b se a<b
}

int arvore_altura(Arvore* a){
    if(arvore_Vazia(a)){
        return -1;
    }else{
        return 1 + maiorEntreOsDois (arvore_altura(a->esq), arvore_altura(a->dir));
    }
}