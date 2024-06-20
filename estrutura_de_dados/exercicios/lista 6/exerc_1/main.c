#include<stdio.h>
#include"listaHet.h"


int main(){

    float maiorArea = 0;

    Triangulo* tri_1 = criaTriangulo(10.0,10.0);
    Triangulo* tri_2 = criaTriangulo(5.0,5.0);
    Retangulo* ret = criaRetangulo(5.0,5.0);
    Circulo* circ = criaCirculo(1.0);
    
    ListaHet* lista = iniciaLista();

    insereTriangulo(lista,tri_1);
    insereRetangulo(lista,ret);
    insereCirculo(lista,circ);
    insereTriangulo(lista,tri_2);


    printf("imprimindo lista:\n");
    imprimeLista(lista);

    maiorArea = max_area(lista);

    printf("Maior area: %.2f\n",maiorArea);

    destroiTriangulo(tri_1);
    destroiTriangulo(tri_2);
    destroiRetangulo(ret);
    destroiCirculo(circ);

    destroiLista(lista);




    return 0;
}