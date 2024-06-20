#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcao.h"

struct matriz{
    int linha;
    int coluna;
    char ***m;
};



Mat* CriaMat(int l, int c){
    Mat* matriz;
    matriz = (Mat*)malloc(sizeof(Mat));
    matriz->linha =l;
    matriz->coluna =c;
    matriz->m = (char***)malloc(l * sizeof(char**));

    for(int i=0;i<matriz->linha;i++){
        matriz->m[i]= (char**)malloc(c*sizeof(char*));
    }

    return matriz;

}
void PreencheMat(Mat *matriz){
    int tam;
    char caract[MAX];
    for(int i=0;i<matriz->linha;i++){
        for(int j=0;j<matriz->coluna;j++){
            scanf("%s",caract);
            tam = strlen(caract);

            matriz->m[i][j]= (char*)malloc(sizeof(char)*tam);
            strcpy(matriz->m[i][j], caract);
        }
    }
}
void ImprimeMat(Mat* matriz){
    for(int i=0;i<matriz->linha;i++){
        for(int j=0;j<matriz->coluna;j++){
            printf("%s ",matriz->m[i][j]);
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