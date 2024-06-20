#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H

//init stack
double* init_stack_double(int size);

//push element to stack
void push_double(double* stack, int* top, double value);

//pop element from stack
double pop_double(double* stack, int* top);

//free stack
void free_stack_double(double* stack);



#endif // STACK_DOUBLE_H