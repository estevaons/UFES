#ifndef CHAR_H
#define CHAR_H


//inicializa vetor de char
char *init_char(int n);

//marca o vetor de char usando os bits do vetor
void mark_char(char *vet, int tam);

//imprime o vetor de char
void print_char(char *vet, int tam);

//libera o vetor de char
void free_char(char *vet);

#endif