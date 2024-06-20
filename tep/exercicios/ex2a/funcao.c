#include<stdio.h>
#include<stdlib.h>
#include"funcao.h"

struct matriz{
    int linha;
    int coluna;
    int **m;
};



Mat* CriaMat(int l, int c){
    Mat* matriz;
    matriz = (Mat*)malloc(sizeof(Mat));
    matriz->linha =l;
    matriz->coluna =c;
    matriz->m = (int**)malloc(l * sizeof(int*));

    for(int i=0;i<matriz->linha;i++){
        matriz->m[i]= (int*)malloc(c*sizeof(int));
    }

    return matriz;

}
void PreencheMat(Mat *matriz){
    int num;
    for(int i=0;i<matriz->linha;i++){
        for(int j=0;j<matriz->coluna;j++){
            scanf("%d",&num);
            matriz->m[i][j]= num;
        }
    }
}
void ImprimeMat(Mat* matriz){
    for(int i=0;i<matriz->linha;i++){
        for(int j=0;j<matriz->coluna;j++){
            printf("%d ",matriz->m[i][j]);
        }
        printf("\n");
    }
}
void Desaloca(Mat* matriz){
    for(int i=0;i<matriz->linha;i++){
        free(matriz->m[i]);
    }
    free(matriz->m);
    free(matriz);
}