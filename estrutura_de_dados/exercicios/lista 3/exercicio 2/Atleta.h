#ifndef Atleta_h
#define Atleta_h

#include<stdio.h>

typedef struct atleta tAtleta;

tAtleta* criaAtleta(char*nome, int id, int idade, float altura, float peso, char* funcao);

char * retornaNome(tAtleta* atl);

char * retornaFuncao(tAtleta* atl);

tAtleta* alteraFuncaoJogador(tAtleta* atl);

int retornaId(tAtleta* atl);

int retornaIdade(tAtleta* atl);

float retornaAltura(tAtleta* atl);

float retornaPeso(tAtleta* atl);

void liberaAtleta(tAtleta* atl);

#endif