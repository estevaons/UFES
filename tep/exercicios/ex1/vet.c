#include<stdio.h>
#include<stdlib.h>
#include "vet.h"


struct  vet{
    int tam;
    int *v;
};

Vetor* CriaVetor(int tamanho){
    Vetor *vec;

    vec = (Vetor*)malloc(sizeof(Vetor)); // aloca dinâmicamente
    vec->tam = tamanho;
    vec->v = (int*)malloc(tamanho*sizeof(int)); // aloca dinâmicamente
    return vec;
}

void PreencheVetor(Vetor *vet){//preenche o vetor com dados do usuário
    int num;

    for(int i=0;i<vet->tam;i++){
        scanf("%d", &num);
        vet->v[i] = num;
    }
}

void SomaVetores(Vetor * vet1, Vetor * vet2){
    for(int i=0; i<vet1->tam;i++){
        printf("%d\n", vet1->v[i]+vet2->v[i]);// imprime a soma dos vetores
    }
}


void ProdutoVetores(Vetor * vet1, Vetor *vet2){
    for(int i=0; i<vet1->tam;i++){
        printf("%d\n", vet1->v[i]*vet2->v[i]);
    }
}

void Desaloca(Vetor *vet){// desaloca a memoria já alocada anteriormente;
    free(vet->v);
    free(vet);
}