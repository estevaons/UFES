#include "kruskal.h"


int get_dimension(FILE* entrada){
    char* line = NULL;
    size_t tamLine;

    int num_dimensions = 0;
    
    getline(&line,&tamLine,entrada);

    char* token = strtok(line,",");

    while(token != NULL){
        num_dimensions++;

        token = strtok(NULL,",");
    }

    rewind(entrada);
    free(line);

    return num_dimensions-1;

}

void kruskal(Aresta** arestas,int numVertices,int numArestas,int k, int* q_id, int* q_sz){
    int numMaxArestas = (numVertices - 1) - (k - 1);
    // printf("Numero maximo de arestas: %d\n",numMaxArestas);
    int countArestas = 0;
    for(int i = 0; i < numArestas;i++){
        int va = arestas[i]->v1;
        int vb = arestas[i]->v2;

        if(!connected_wq(q_id,va,vb)){
            countArestas++;
            union_wq(q_id,q_sz,va,vb);            
        }
        
        if(countArestas == numMaxArestas){
            break;
        }
    }
}

void print_groups(int numVertices,int* q_id,int k,Vertice** vertices,FILE* saida){
    
    int firstElement = 1;
    int* verificado = (int*)calloc(numVertices,sizeof(int));
    int countConjuntos = 0;
    
    for(int i = 0; i < numVertices; i++){
        int root = find_wq(q_id,i);

        if(verificado[i] == 1){
            continue;
        }else{

            for(int j = i; j < numVertices; j++){
                if(verificado[j] == 1){
                    continue;
                }
                if(root == find_wq(q_id,j)){
                    if(firstElement){
                        fprintf(saida,"%s",vertices[j]->id);
                        firstElement = 0;
                    }else{
                        fprintf(saida,",%s",vertices[j]->id);
                    }
                    verificado[j] = 1;
                }
            }
            fprintf(saida,"\n");

            firstElement = 1;
            countConjuntos++;

            if(countConjuntos == k){
                break;
            }
        }
    }

    fclose(saida);
    free(verificado);
}