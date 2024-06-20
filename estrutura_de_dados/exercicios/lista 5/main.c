#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista_dpl.h"



int main(){

    Item* item1 = iniciaItem(1,32.54,"chinelo");
    Item* item2 = iniciaItem(2,43.21,"bone");
    Item* item3 = iniciaItem(3,54.32,"mochila");
    Item* item4 = iniciaItem(4,102.43,"camisa");

    ListaD* listaDPL = iniciaLista();


    listaDPL = insereNaLista(listaDPL,item1);
    listaDPL = insereNaLista(listaDPL,item2);
    listaDPL = insereNaLista(listaDPL,item3);
    listaDPL = insereNaLista(listaDPL,item4);

    imprimeLista(listaDPL);


    listaDPL = retiraDaLista(listaDPL,"mochila"); // retira caso comum

    printf("-----------------\n");
    printf("RETIRANDO CASO COMUM\n");
    imprimeLista(listaDPL);


    listaDPL = retiraDaLista(listaDPL,"chinelo"); // retira primeiro

    printf("-----------------\n");
    printf("RETIRANDO PRIMEIRO\n");
    imprimeLista(listaDPL);



    listaDPL = retiraDaLista(listaDPL,"camisa"); // retira ultimo

    printf("-----------------\n");
    printf("RETIRANDO ULTIMO\n");
    imprimeLista(listaDPL);



    // inserindo itens novamente a lista
    listaDPL = insereNaLista(listaDPL,item3);
    listaDPL = insereNaLista(listaDPL,item1);
    listaDPL = insereNaLista(listaDPL,item4);


    printf("-----------------\n");
    printf("INSERINDO ITENS NOVAMENTE A LISTA NA ORDEM RETIRADA\n");
    imprimeLista(listaDPL);



    destroiLista(listaDPL);

    destroiItem(item1);
    destroiItem(item2);
    destroiItem(item3);
    destroiItem(item4);



    return 0;
}