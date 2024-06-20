#include "kruskal.h"
#include <time.h>

int main(int argc, char* argv[]){

    //pega o valor do argumento da linha de comando
    int k = atoi(argv[2]);

    //relogio
    clock_t startT,stopT,startD,stopD,startL,stopL,startO,stopO,startM,stopM,startE,stopE;
    startT = clock(); 
   
    
    FILE* entrada = fopen(argv[1],"r");

    //pega o numero de dimensoes dos pontos que estao no arquivo
    int numDimensions = get_dimension(entrada);

    //cria vetor de vertices
    Vertice** vertices = (Vertice**)malloc(1000*sizeof(Vertice*));

    //le o arquivo e preenche o vetor de vertices e retorna o numero de vertices
    startL = clock();
    int numVertices = read_file(&vertices,numDimensions,entrada);
    stopL = clock();

    //realoca o vetor de vertices para o tamanho correto
    vertices = (Vertice**)realloc(vertices,numVertices*sizeof(Vertice*));

    //ordena o vetor de vertices
    qsort(vertices,numVertices,sizeof(Vertice*),comparaVertices);

    fclose(entrada);
    
    //calcula o numero de arestas
    int numArestas = (((numVertices*numVertices)-numVertices)/2);

    //cria vetor de arestas
    Aresta** arestas = (Aresta**)malloc(numArestas*sizeof(Aresta*));
    //preenche o vetor de arestas calculando a distancia entre os vertices
    startD = clock(); 
    preencheArestas(arestas,vertices,numVertices, numDimensions);
    stopD = clock();
    
    //ordena o vetor de arestas
    startO = clock();
    qsort(arestas,numArestas,sizeof(Aresta*),comparaAresta);
    stopO = clock();


    // cria vetores para o quick union
    int* q_id = (int*)malloc(numVertices*sizeof(int));
    int* q_sz = (int*)malloc(numVertices*sizeof(int));

    //inicializa o quick union
    init_vector_wq(q_id,q_sz,numVertices);

    //calcula mst utilizando kruskal
    startM = clock();
    kruskal(arestas,numVertices,numArestas,k,q_id,q_sz);
    stopM = clock();

    FILE* saida = fopen(argv[3],"w");
    //imprime os grupos
<<<<<<< HEAD
    print_groups(numVertices,q_id,k,vertices,saida);
=======
    startE = clock();
    print_groups(numVertices,q_id,k,vertices);
    stopE = clock();
>>>>>>> 913a2dd71fdee33c97c82035099f9efcb889cd2f

    free(q_id);
    free(q_sz);
    liberaVertices(vertices,numVertices);
    liberaArestas(arestas,numArestas);

 
    stopT = clock();
    printf("Tempo de execução total: %f\n",((double)(stopT-startT))/CLOCKS_PER_SEC);
    // printf("Tempo de execução da leitura do arquivo: %f\n",((double)(stopL-startL))/CLOCKS_PER_SEC);
    // printf("Tempo de execução do calculo de distancias: %f\n",((double)(stopD-startD))/CLOCKS_PER_SEC);
    // printf("Tempo de execução da ordenação das arestas: %f\n",((double)(stopO-startO))/CLOCKS_PER_SEC);
    // printf("Tempo de execução da MST: %f\n",((double)(stopM-startM))/CLOCKS_PER_SEC);
    // printf("Tempo de execução da escrita do arquivo: %f\n",((double)(stopE-startE))/CLOCKS_PER_SEC);


    return 0;

}