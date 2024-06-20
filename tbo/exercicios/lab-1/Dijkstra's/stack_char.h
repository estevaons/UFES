#ifndef DIJKSTRA_CHAR_H
#define DIJKSTRA_CHAR_H

//inicializa uma pilha de operandos
char* init_stack_char(int size);

//adiciona um elemento na pilha
void push_char(char* stack, int* top, char data);

//remove um elemento da pilha
char pop_char(char* stack, int* top);

//libera a pilha
void free_stack_char(char* stack);

#endif