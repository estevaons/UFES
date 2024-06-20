#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "dijkstra.h"
#include "grafo.h"
#include "vertice.h"
#include "PQ.h"


Vertice make_vertice(int id, double value) {
    Vertice t;
    id(t) = id;
    value(t) = value;
    return t;
}


int* dijkstra(Grafo* grafo, int origem, int destino, int* caminho, int* tamanho_caminho){ 
    int num_vertices = grafo->num_vertices;
    // Inicializa o vetor de distâncias
    double* distTo = (double*)malloc((num_vertices +1) * sizeof(double));
    int* edgeTo = (int*)malloc((num_vertices +1) * sizeof(int));
    distTo[origem] = 0;

    // Inicializa fila de prioridade
    Vertice* pq = (Vertice*)malloc((num_vertices+1) * sizeof(Vertice));
    int* map = (int*)malloc((num_vertices+1) * sizeof(int));
    int N = 0;

    for (int i = 1; i <= num_vertices; i++) {
        if (i != origem) {
            distTo[i] = DBL_MAX;
        }
        edgeTo[i] = -1;
        PQ_insert(make_vertice(i, distTo[i]), pq, map, &N);
    }

    while (!PQ_empty(&N)) {
        Vertice p = PQ_delmin(pq, map, &N);
        
        int v = id(p);

        //usando matriz de adjacencia
        for (int i = 1; i <= num_vertices; i++) {
            if (grafo->matriz_adj[v][i] != NULL) {
                int w = i;
                if (distTo[w] > distTo[v] + grafo->matriz_adj[v][i]->time) {
                    distTo[w] = distTo[v] + grafo->matriz_adj[v][i]->time;
                    edgeTo[w] = v;
                    PQ_decrease_key(w, distTo[w], pq, map);
                }
            }
        }

    }

    //criar caminho
    int i = 0;
    int v = destino;
    while (v != origem) {
        caminho[i++] = v;
        v = edgeTo[v];
    }
    caminho[i++] = origem;
    caminho[i] = -1;

    *tamanho_caminho = i;

    free(distTo);
    free(edgeTo);
    free(pq);
    free(map);

    return caminho;

}


int* GPS(Grafo* grafo, int origem, int destino,int* caminho_final, int* tam_caminho_final){
    int* caminho = (int*)malloc((grafo->num_vertices) * sizeof(int));
    caminho_final[0] = origem;
    int tam_caminho = 0;
    int state = origem;
    int j = 0;


    //atualiza as arestas
    atualiza_arestas(grafo, grafo->tempo_total);

    while (state != destino){
        j++;
        //atualiza as arestas
        atualiza_arestas(grafo, grafo->tempo_total);
        int state_anterior = state;
        caminho = dijkstra(grafo, state, destino, caminho, &tam_caminho);
        state = caminho[tam_caminho-2];
        caminho_final[j] = state;
        //simula o deslocamento do carro
        simula_deslocamento(grafo, state_anterior, state);
    }

    *tam_caminho_final = j;


    free(caminho);
}

void print_arquivo(Grafo* grafo,FILE* saida ,int* caminho_final, int tam_caminho_final){
    // imprime caminho final
    for(int i = 0; i<=tam_caminho_final; i++){
        if(i==tam_caminho_final){
            fprintf(saida,"%d", caminho_final[i]);
            break;
        }
        fprintf(saida,"%d;", caminho_final[i]);
    }
    fprintf(saida,"\n");

    //imprime km total
    fprintf(saida,"%.15lf\n", grafo->km_total/1000);

    //converte tempo total para HH:MM:SS.fff
    int horas = grafo->tempo_total/3600;
    int minutos = (grafo->tempo_total - horas*3600)/60;
    double segundos = grafo->tempo_total - horas*3600 - minutos*60;
    fprintf(saida,"%02d:%02d:%06.15lf\n", horas, minutos, segundos);
}