#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "josefo.h"


int main(int argc, char *argv[]){

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    bool *v = init_bool(n);
    int *v_aux = init_int(n);

    josefo(v, n, m, v_aux);

    // print_int(v_aux, n);

    free_bool(v);
    free_int(v_aux);

    return 0;
}