#ifndef RBT_H
#define RBT_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct node RBT;

bool is_red(RBT *x);

RBT* rotate_left(RBT *h);

RBT* rotate_right(RBT *h);

void flip_colors(RBT *h);

RBT* RBT_insert(RBT *h, char* key, void* val, bool isStopWord);

void* search(RBT *n, char* key);

void RBT_destroy(RBT* n, void (*Libera) (void*));

void RBT_print(RBT* n, int i);

RBT* GetLeft(RBT* n);

RBT* GetRight(RBT* n);

void* GetValue(RBT* n);
void tempPrint(RBT* n);
#endif