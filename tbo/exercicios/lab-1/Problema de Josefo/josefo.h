#ifndef JOSEFO_H
#define JOSEFO_H

//inicializa vetor de booleano
bool* init_bool(int n);

//inicializa vetor auxiliar
int* init_int(int n);

//marca os eliminados no vetor de booleano
void josefo(bool *v, int n, int m, int* v_aux);

//imprimi o vetor de booleano
void print_bool(bool *v, int n);

//imprimi o vetor auxiliar
void print_int(int *v, int n);

//libera o vetor de booleano
void free_bool(bool *v);

//libera o vetor auxiliar
void free_int(int *v);

#endif