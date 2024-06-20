#ifndef Campeonato_h
#define Campeonato_h

#include<stdio.h>
#include"Partida.h"

typedef struct campeonato tCampeonato;

tCampeonato* criaCampeonato(char* nome, int qtdJogos);

void adicionaPartida(tCampeonato* campeonato, tPartida* partida);
void removePartida(tCampeonato* campeonato, tPartida* partida);

tTime* retnornaTimeVencedor(tCampeonato* campeonato);

tAtleta* retornaArtilheiroDoCampeonato(tCampeonato* campeonato);

void liberaCampeonato(tCampeonato* campeonato);

#endif