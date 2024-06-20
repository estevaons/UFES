#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Grafo* cria_grafo(FILE* entrada){

    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    char* line = NULL;
    size_t tam_line;
    ssize_t characters;

    grafo->tempo_total = 0;
    grafo->km_total = 0;

    //le a primeira linha
    characters = getline(&line, &tam_line, entrada);
    char* token = strtok(line, ";");
    grafo->num_vertices = atoi(token);
    grafo->vertices = (int*) malloc((grafo->num_vertices +1) * sizeof(int));
    
    //cria matriz de adjacencia
    grafo->matriz_adj = (Aresta***) malloc((grafo->num_vertices +1) * sizeof(Aresta**));
    //aloca as linhas da matriz
    for(int i=1; i <= grafo->num_vertices; i++){
        grafo->matriz_adj[i] = (Aresta**) malloc((grafo->num_vertices +1) * sizeof(Aresta*));
        for(int j=1; j <= grafo->num_vertices; j++){
            grafo->matriz_adj[i][j] = NULL;
        }
    }

    //preenche o vetor de vertices
    for(int i=1; i <= grafo->num_vertices; i++){
        grafo->vertices[i] = i;
    }

    token = strtok(NULL, ";");
    grafo->num_arestas = atoi(token);
    grafo->arestas = (Aresta**) malloc(grafo->num_arestas * sizeof(Aresta*));


    //le a segunda linha
    characters = getline(&line, &tam_line, entrada);
    token = strtok(line, ";");
    grafo->src = atoi(token);
    token = strtok(NULL, ";");
    grafo->dest = atoi(token);

    // //le a terceira linha
    characters = getline(&line, &tam_line, entrada);
    token = strtok(line, ";");
    grafo->velocidade = atof(token)/3.6;


    // le as proximas linhas que são as arestas
    for(int i=0; i < grafo->num_arestas; i++){
        characters = getline(&line, &tam_line, entrada);
        token = strtok(line, ";");
        int origem = atoi(token);
        token = strtok(NULL, ";");
        int destino = atoi(token);
        token = strtok(NULL, ";");
        double distancia = atof(token);
        Aresta* aresta = cria_aresta(origem, destino, distancia, grafo->velocidade);
        grafo->matriz_adj[origem][destino] = aresta;
        grafo->arestas[i] = aresta;
    }

    //declara vetor de atualizações de tamanho 1000
    grafo->tam_att = 0;
    grafo->att = (Att**) malloc(1000 * sizeof(Att*));

    //le as proximas linhas que são as atualizações
    while((characters = getline(&line, &tam_line, entrada)) != -1){
        //realoca o vetor de atualizações caso precise
        if(((grafo->tam_att+1) % 1000) == 0){
            grafo->att = (Att**) realloc(grafo->att, (2*(grafo->tam_att + 1)) * sizeof(Att*));
        }
        token = strtok(line, ";");
        double time = atoi(token);
        token = strtok(NULL, ";");
        int origem = atoi(token);
        token = strtok(NULL, ";");
        int destino = atof(token);
        token = strtok(NULL, ";");
        double velocidade = atof(token)/3.6;
        Att* att = cria_att(time, origem, destino, velocidade);
        grafo->att[grafo->tam_att] = att;
        grafo->tam_att++;
    }

    //realoca o vetor de atualizações para o tamanho exato
    grafo->att = (Att**) realloc(grafo->att, (grafo->tam_att) * sizeof(Att*));


    //libera a linha
    free(line);
    
    return grafo;

}


void atualiza_arestas(Grafo* grafo, double time){
    for(int i=0; i < grafo->tam_att; i++){
        if(grafo->att[i]->time <= time){
            grafo->matriz_adj[grafo->att[i]->origem][grafo->att[i]->destino]->velocidade = grafo->att[i]->velocidade;
            grafo->matriz_adj[grafo->att[i]->origem][grafo->att[i]->destino]->time =  grafo->matriz_adj[grafo->att[i]->origem][grafo->att[i]->destino]->distancia/ grafo->matriz_adj[grafo->att[i]->origem][grafo->att[i]->destino]->velocidade;
        }
    }
}

void libera_grafo(Grafo* grafo) {


    for(int i=0; i<grafo->num_arestas; i++){
        free(grafo->arestas[i]);
    }
    free(grafo->arestas);

    for(int i=0; i<grafo->tam_att; i++){
        free(grafo->att[i]);
    }
    free(grafo->att);

    for(int i=1; i <= grafo->num_vertices; i++){
        free(grafo->matriz_adj[i]);
    }

    free(grafo->matriz_adj);

    free(grafo->vertices);

    free(grafo);

}

void simula_deslocamento(Grafo* grafo, int origem, int destino){
    grafo->tempo_total += grafo->matriz_adj[origem][destino]->time;
    grafo->km_total += grafo->matriz_adj[origem][destino]->distancia;
}