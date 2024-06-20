#include<stdio.h>
#include"listaMat.h"


int main(){

    Matriz* mat1 = inicializaMatriz(2,3);
    Matriz* mat2 = inicializaMatriz(3,2);
    Matriz* mat3 = inicializaMatriz(4,3);
    Matriz* mat4 = inicializaMatriz(3,4);




    for(int i =0 ; i<2;i++){
        for(int j=0; j<3; j++){
            modificaElemento(mat1,i,j,0);
        }
    }

    for(int i =0 ; i<3;i++){
        for(int j=0; j<2; j++){
            modificaElemento(mat2,i,j,1);
        }
    }

    for(int i =0 ; i<4;i++){
        for(int j=0; j<3; j++){
            modificaElemento(mat3,i,j,2);
        }
    }

    for(int i =0 ; i<3;i++){
        for(int j=0; j<4; j++){
            modificaElemento(mat4,i,j,3);
        }
    }

    ListaDeMatrizes* listaMAT = iniciaListaDeMatrizes();


    
    insereListaMat(listaMAT, mat1);
    insereListaMat(listaMAT, mat2);
    insereListaMat(listaMAT, mat3);
    insereListaMat(listaMAT, mat4);


    printf("Imprimindo lista:\n");

    imprimeListaMat(listaMAT);


    ListaDeMatrizes* listaTrpMat = iniciaListaDeMatrizes();


    Matriz* matTRP1 = transposta(mat1);
    Matriz* matTRP2 = transposta(mat2);
    Matriz* matTRP3 = transposta(mat3);
    Matriz* matTRP4 = transposta(mat4);


    insereListaMat(listaTrpMat,matTRP1);
    insereListaMat(listaTrpMat,matTRP2);
    insereListaMat(listaTrpMat,matTRP3);
    insereListaMat(listaTrpMat,matTRP4);

    printf("Imprimindo lista TRANSPOSTA:\n");

    imprimeListaMat(listaTrpMat);

    printf("LISTA DE MATRIZES RETIRANDO PRIMEIRA POSIÇÂO:\n");

    removeMatrizDaLista(listaMAT,mat1);
    removeMatrizDaLista(listaTrpMat,matTRP1);

    imprimeListaMat(listaMAT);
    printf("Imprimindo lista TRANSPOSTA:\n");
    imprimeListaMat(listaTrpMat);




    printf("LISTA DE MATRIZES RETIRANDO CASO COMUM:\n");

    removeMatrizDaLista(listaMAT,mat3);
    removeMatrizDaLista(listaTrpMat,matTRP3);

    imprimeListaMat(listaMAT);
    printf("Imprimindo lista TRANSPOSTA:\n");
    imprimeListaMat(listaTrpMat);



    printf("LISTA DE MATRIZES RETIRANDO ULTIMA POSIÇÂO:\n");

    removeMatrizDaLista(listaMAT,mat4);
    removeMatrizDaLista(listaTrpMat,matTRP4);

    imprimeListaMat(listaMAT);
    printf("Imprimindo lista TRANSPOSTA:\n");
    imprimeListaMat(listaTrpMat);




    printf("INSERINDO NOVAMENTE MATRIZES RETIRADAS\n");
    insereListaMat(listaMAT,mat1);
    insereListaMat(listaMAT,mat4);
    insereListaMat(listaMAT,mat3);

    insereListaMat(listaTrpMat,matTRP1);
    insereListaMat(listaTrpMat,matTRP4);
    insereListaMat(listaTrpMat,matTRP3);


    imprimeListaMat(listaMAT);
    printf("Imprimindo lista TRANSPOSTA:\n");
    imprimeListaMat(listaTrpMat);


    liberaListaMat(listaMAT);
    liberaListaMat(listaTrpMat);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
    destroiMatriz(mat4);

    destroiMatriz(matTRP1);
    destroiMatriz(matTRP2);
    destroiMatriz(matTRP3);
    destroiMatriz(matTRP4);


    return 0;
}