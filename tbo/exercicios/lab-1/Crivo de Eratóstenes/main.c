#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "int.h"
#include "bool.h"
#include "char.h"
#include "time.h"

int main(int argc, char *argv[]){

    //inicio da contagem de tempo
    clock_t start = clock();

    int n = atoi(argv[1]);

    //inicializa o vetor
    // int *v = init_int(n);
    // bool *v = init_bool(n);
    char *v = init_char(n);
    

    //retorna o vetor com os números primos
    // mark_int(v, n);
    // mark_bool(v, n);
    mark_char(v, n);

    //imprime o vetor
    // print_int(v, n);
    // print_bool(v, n);
    // printVetChar(v, n);

    //libera a memória alocada para o vetor
    // free_int(v);
    // free_bool(v);
    free_char(v);

    //fim da contagem de tempo
    clock_t end = clock();

    //imprime o tempo
    printf("\nTempo: %f", (double)(end - start) / CLOCKS_PER_SEC);
  
    return 0;
}



/*
    Algoritimo que o professor Giovanni sugeriu
    cria um vetor de char
    cada char tem 8 bits
    dado um número i precisaremos encontrar em qual byte ele está
    e dentro de qual byte precisaremos encontrar qual bit se refere se o número i está marcado
    para encontrar qual byte se refere ao número i faremos i/qtdBitsChar
    para encontrar qual bit se refere ao número i dentro do byte especifico paremos i%8
    para setar o bit dentro do vetor usaremos v[1/8] = v[i/8] | (1<<(i%8))
    sendo (1<<(i%8)) a mascara que usaremos para setar o bit
*/