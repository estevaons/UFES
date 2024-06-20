#include "vertice.h"


Vertice* criaVertice(int dimension, char* id){
    Vertice* v = (Vertice*)malloc(sizeof(Vertice));
   
    v->id = (char*)malloc((strlen(id)+1)*sizeof(char));
    strcpy(v->id,id);
    v->coords = (float*)malloc(dimension*sizeof(float));
    
    return v;
}

int comparaVertices(const void* a, const void* b){
    const Vertice** v1 = (const Vertice**)a;
    const Vertice** v2 = (const Vertice**)b;

    return strcmp((*v1)->id,(*v2)->id);
}



int read_file(Vertice*** v, int dimension, FILE* entrada) {
    char* line = NULL;
    size_t tam_line;
    ssize_t characters;

    int isID = 1, count_vertices = 0, count_coords = 0;

    while ((characters = getline(&line, &tam_line, entrada)) != -1) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            if (isID) {
                if (((count_vertices + 1) % 1000) == 0) {
                    // Realoca o vetor de vértices
                    *v = realloc(*v, (2 * (count_vertices + 1)) * sizeof(Vertice*));
                }
                // Cria um novo vértice e o adiciona ao vetor de vértices
                (*v)[count_vertices] = criaVertice(dimension, token);
                isID = 0;
            } else {
                (*v)[count_vertices]->coords[count_coords] = atof(token);
                count_coords++;
            }
            token = strtok(NULL, ",");
        }
        count_coords = 0;
        count_vertices++;
        isID = 1;
    }

    free(line);

    return count_vertices;
}

void liberaVertices(Vertice** v, int num_vertices){
    for(int i = 0; i < num_vertices; i++){
        free(v[i]->coords);
        free(v[i]->id);
        free(v[i]);
    }
    free(v);
}
