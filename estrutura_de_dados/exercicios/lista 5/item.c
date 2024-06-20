#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"


struct item{
    int id;
    float preco;
    char* nome;
};

Item* iniciaItem(int id, float preco, char* nome){
    Item* item = (Item*)malloc(sizeof(Item));//aloca item
    item->id = id;
    item->preco = preco;
    item->nome = strdup(nome);

    return item;
}


char* recuperaNomeItem(Item* item){
    return item->nome;
}

float recuperaPrecoItem(Item* item){
    return item->preco;
}

int recuperaIdItem(Item* item){
    return item->id;
}

void imprimeItem(Item * item){
    printf("ITEM: %s\nID: %d\nPRECO: %.2f\n\n",item->nome,item->id,item->preco);
}

void destroiItem(Item* item){
    free(item->nome);
    free(item);
}