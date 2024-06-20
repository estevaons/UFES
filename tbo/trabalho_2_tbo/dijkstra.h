#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

int* dijkstra(Grafo* grafo, int origem, int destino, int* caminho, int* tamanho_caminho);

int* GPS(Grafo* grafo, int origem, int destino,int* caminho_final, int* tam_caminho_final);

void print_arquivo(Grafo* grafo,FILE* saida ,int* caminho_final, int tam_caminho_final);


#endif