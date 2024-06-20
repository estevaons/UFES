#include<stdio.h>
#include "funcao.h"

int main(){
    int l=2,c=2;
    Mat* matriz;

    matriz= CriaMat(l,c);
    PreencheMat(matriz);
    ImprimeMat(matriz);
    Desaloca(matriz);



    return 0;
}