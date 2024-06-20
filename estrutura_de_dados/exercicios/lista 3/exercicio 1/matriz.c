#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

//vamos usar o método de vetor de ponteiros para implementar a matriz
struct matriz
{
    int nlinha;
    int ncolunas;
    int **vetorDePonteiros;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    int i=0;
    Matriz *matriz;
    matriz = (Matriz*)malloc(sizeof(Matriz));// instância a estrutura matriz
    
    matriz->nlinha = nlinhas;
    matriz->ncolunas = ncolunas;

    matriz->vetorDePonteiros = (int**)malloc( matriz->nlinha * sizeof(int*));// instância o vetor de ponteiros (matriz)

    for(i=0;i<nlinhas;i++){
        matriz->vetorDePonteiros[i]=(int*)malloc(matriz->ncolunas * sizeof(int));// instância cada linha da matriz que é um vetor de ponteiros
    }

    return matriz;

}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->vetorDePonteiros[linha][coluna] = elem; // modifica o vetorDePonteiros na pos [i][j];  
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    int elem = mat->vetorDePonteiros[linha][coluna];
    return elem;
}

int recuperaNColunas (Matriz* mat){
    int numColunas = mat->ncolunas;
    return numColunas;
}

int recuperaNLinhas (Matriz* mat){
    int numLinhas = mat->nlinha;
    return numLinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz* matrizTRP;

    matrizTRP = inicializaMatriz(mat->ncolunas, mat->nlinha);// como a matriz é transposta
    //passamos primeiro numero de colunas e depous numero de linhas
    //já que a função recebe primeiro nlinhas e dps nColunas

    int i=0,j=0;
    for(i=0;i<matrizTRP->nlinha;i++){
        for(j=0;j<matrizTRP->ncolunas;j++){
            matrizTRP->vetorDePonteiros[i][j] = mat->vetorDePonteiros[j][i];
        }
    }
    //fazemos o for dentro de outro for para acessar as posições do vetor de ponteiros e inverter para
    //matriz transposta

    return matrizTRP;

}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz *matrizMULT;
    //resultado de multiplicação de matriz (m x p * p x n = m x n)

    //analisa condição para existir a multiplicação de matrizes
    if(mat1->ncolunas != mat2->nlinha){
        printf("as matrizes n podem ser multiplicadas!\n");
        exit(0);
    }

    matrizMULT = inicializaMatriz(mat1->nlinha , mat2->ncolunas);

    int i=0,j=0,k=0,t=0;

    for(i=0;i<matrizMULT->nlinha;i++){
        for(j=0;j<matrizMULT->ncolunas;j++){
            t=0;
            for(k=0;k<mat1->ncolunas;k++){//percorre as colunas da primeira matriz
                t= t+ (mat1->vetorDePonteiros[i][k]*mat2->vetorDePonteiros[k][j]);
            }
            matrizMULT->vetorDePonteiros[i][j] = t;
        }
    }
    return matrizMULT;
}

void imprimeMatriz(Matriz* mat){
    int i=0,j=0;
    for(i=0;i<mat->nlinha;i++){
        for(j=0; j<mat->ncolunas;j++){
            printf("%d ",mat->vetorDePonteiros[i][j]);
        }
        printf("\n");// para quebrar a linha
    }
}

void destroiMatriz(Matriz* mat){
    int i=0;
    for(i=0; i<mat->nlinha;i++){
        free(mat->vetorDePonteiros[i]);// primeiro liberamos cada posição do vetor de ponteiro
    }
    free(mat->vetorDePonteiros);// liberamos o vetor de ponteiro
    free(mat); // liberamos a estrutura mat
}