#ifndef Time_h
#define Time_h

#include<stdio.h>
#include "Atleta.h"


typedef struct time tTime;


tTime* CriaTime(char* nome, int qtdJogadores);

tTime* adicionaJogador(tTime* time, tAtleta* atl);

tTime* removeJogador(tTime* time, tAtleta* atl);

char* retornaNomeDoTime(tTime* time);

tTime* alteraNomeDoTime(tTime* time);

int retornaQtdJogadoresDoTime(tTime* time);


void liberaTime(tTime* time);


#endif