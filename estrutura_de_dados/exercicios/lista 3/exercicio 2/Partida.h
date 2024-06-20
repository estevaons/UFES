#ifndef Partida_h
#define Partida_h

#include<stdio.h>
#include"Time.h"


typedef struct partida tPartida;

tPartida* criaPartida(tTime* t1, tTime* t2, char* data);

void AtribuiVencedor(tPartida* partida, tTime* time);

tTime* retornaVencedor(tPartida* partida);

int numeroDeGolsDaPartida(tPartida* partida);

tAtleta* artilheiroDaPartida(tPartida* partida);

int numeroDeFaltas(tPartida* partida);

void liberaPartida(tPartida* partida);


#endif