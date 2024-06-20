#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvoreBB.h"

struct arv{
    Aluno* aluno;
    struct arv* esq;
    struct arv* dir;
};

Arvore* arvoreBB_Cria(){
    return NULL;
}

Arvore* arvoreBB_Libera(Arvore* a){
    if(!arvore_Vazia(a)){
        arvoreBB_Libera(a->esq);
        arvoreBB_Libera(a->dir);
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

void arvoreBB_Imprime(Arvore* a){
    
    if(a != NULL){
        arvoreBB_Imprime(a->esq);
        imprimeAluno(a->aluno);
        arvoreBB_Imprime(a->dir);
    }
}

Arvore* arvoreBB_Busca(Arvore* a, int chave){
    if(a == NULL){
        return NULL;
    }
    else if(retornaMatriculaAluno(a->aluno) > chave){
        return arvoreBB_Busca(a->esq,chave);
    }
    else if(retornaMatriculaAluno(a->aluno) < chave){
        return arvoreBB_Busca(a->dir,chave);
    }else{
        return a;
    }
}

Arvore* arvoreBB_Insere(Arvore* a, Aluno* al){
    if(a == NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->aluno = al;
        a->esq = a->dir = NULL;
    }
    else if(retornaMatriculaAluno(al) < retornaMatriculaAluno(a->aluno)){
        a->esq = arvoreBB_Insere(a->esq, al);
    }else{
        a->dir = arvoreBB_Insere(a->dir,al);
    }
    return a;

}

Arvore* arvoreBB_Retira(Arvore* a, int matricula){
    if(a == NULL){
        return NULL;
    }
    else if(retornaMatriculaAluno(a->aluno) > matricula){
        a->esq = arvoreBB_Retira(a->esq, matricula);
    }
    else if(retornaMatriculaAluno(a->aluno) < matricula){
        a->dir = arvoreBB_Retira(a->dir, matricula);
    }else{
        if(a->esq == NULL && a->dir == NULL){
            free(a);
            a = NULL;
        }
        else if(a->esq == NULL){
            Arvore* temp = a;
            a = a->dir;
            free(temp);
        }
        else if(a->dir == NULL){
            Arvore* temp = a;
            a = a->esq;
            free(temp);
        }else{
            Arvore* aux = a->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
                Aluno* alTemp = a->aluno;
                a->aluno = aux->aluno;
                aux->aluno = alTemp;

                a->esq = arvoreBB_Retira(a->esq,matricula);
            }
        }

    }
    return a;
}






