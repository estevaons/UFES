#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    
    Item *v = malloc(n * sizeof(Item));

    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    clock_t start, stop;
    start = clock();
    //ordenar
    sort(v, 0, n-1);
    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    //imprimir
    // for (int i=0; i<n; i++){
    //     printf("%d ", v[i]);
    // }

    //imprimir tempo
    printf("Tempo: %f\n", time_taken);

    //liberar memoria
    free(v);

 

    return 0;

}