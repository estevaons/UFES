#include "professor.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct professor{
    int siape;
    char* nome;
    float salario;
};

Professor* iniciaProfessor(int siape, char* nome, float salario){
    Professor* prof = (Professor*)malloc(sizeof(Professor));

    prof->siape = siape;
    prof->nome = strdup(nome);
    prof->salario = salario;

    return prof;
}

void imprimeProfessor(Professor* prof){
    printf("Nome: %s, Siape: %d, Salario: %.2f\n",prof->nome,prof->siape,prof->salario);
}

int retornaSiapeProfessor(Professor* prof){
    return prof->siape;
}

float retornaSalarioProfessor(Professor* prof){
    return prof->salario;
}

char* retornaNomeProfessor(Professor* prof){
    return prof->nome;
}

void liberaProfessor(Professor* prof){
    free(prof->nome);
    free(prof);
}