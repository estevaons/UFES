#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack_char.h"


char* init_stack_char(int size){
    char* stack = (char*)malloc(size*sizeof(char));
    return stack;
}

void push_char(char* stack, int* top, char data){
    stack[++(*top)] = data;
}

char pop_char(char* stack, int* top){
    return stack[(*top)--];
}

void free_stack_char(char* stack){
    free(stack);
}
