#include "aresta.h"

Aresta* criaAresta(int v1, int v2, float peso){
    Aresta* a = (Aresta*) malloc(sizeof(Aresta));
    a->v1 = v1;
    a->v2 = v2;
    a->peso = peso;
    
    return a;
}

int comparaAresta(const void* a, const void* b){
    Aresta* a1 = *(Aresta**)a;
    Aresta* a2 = *(Aresta**)b;
    if(a1->peso < a2->peso){
        return -1;
    }
    else if(a1->peso > a2->peso){
        return 1;
    }
    else{
        return 0;
    }
}

double calculaDistancia(Vertice* v1,Vertice* v2, int num_dimensions){
    double dist = 0;
    for(int k = 0; k < num_dimensions; k++){
        dist += pow(v1->coords[k] - v2->coords[k],2);
    }
    dist = sqrt(dist);

    return dist;
    
}

void preencheArestas(Aresta** arestas, Vertice** v, int num_vertices,int num_dimensions){
    int countArestas = 0;
    double dist = 0;
    for(int i=0; i<num_vertices-1; i++){
        for(int j=i+1; j<num_vertices; j++){
            
            dist = calculaDistancia(v[i],v[j],num_dimensions);

            arestas[countArestas] = criaAresta(i,j,dist);
            
            countArestas++;
        }
    }
}

void liberaArestas(Aresta** arestas, int num_arestas){
    for(int i = 0; i < num_arestas; i++){
        free(arestas[i]);
    }
    free(arestas);
}

