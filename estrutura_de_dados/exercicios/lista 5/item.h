#ifndef ITEM_H
#define ITEM_H


typedef struct item Item;

Item* iniciaItem(int id, float preco, char* nome);

char* recuperaNomeItem(Item* item);

float recuperaPrecoItem(Item* item);

int recuperaIdItem(Item* item);

void imprimeItem(Item * item);

void destroiItem(Item* item);



#endif