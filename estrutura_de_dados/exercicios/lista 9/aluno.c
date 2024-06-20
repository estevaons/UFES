#include "aluno.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct al{
    char* nome;
    int matricula;
    float cr;
};


Aluno* iniciaAluno(char* nome, int matricula, float cr){
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->cr = cr;

    return aluno;
}

char* retornaNomeAluno(Aluno* al){
    return al->nome;
}

int retornaMatriculaAluno(Aluno* al){
    return al->matricula;
}

float retornaCrAluno(Aluno* al){
    return al->cr;
}

void imprimeAluno(Aluno* al){
    printf("ALUNO: %d, Nome: %s, CR: %.2f\n",al->matricula,al->nome,al->cr);
}

void liberaAluno(Aluno* al){
    free(al->nome);
    free(al);
}