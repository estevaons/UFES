#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack_double.h"


double* init_stack_double(int size){
    double* stack = (double*)malloc(size*sizeof(double));
    return stack;
}

void push_double(double* stack, int* top, double data){
    stack[++(*top)] = data;
}

double pop_double(double* stack, int* top){
    return stack[(*top)--];
}

void free_stack_double(double* stack){
    free(stack);
}