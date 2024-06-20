#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dijkstra.h"
#include "PQ.h"
#include "vertice.h"
#include "aresta.h"


int main(int argc, char* argv[]){
    //iniciando arquivos de entrada e saida
    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");
    Grafo *grafo = cria_grafo(entrada);
    int* caminho_final = (int*)malloc((grafo->num_vertices) * sizeof(int));
    int tam_caminho_final = 0;

    //simula o gps
    GPS(grafo,grafo->src,grafo->dest,caminho_final,&tam_caminho_final);

    //imprime o caminho final no arquivo de saida
    print_arquivo(grafo,saida,caminho_final,tam_caminho_final);
 
    //libera memoria
    libera_grafo(grafo);
    free(caminho_final);

    fclose(entrada);
    fclose(saida);
    return 0;
}
