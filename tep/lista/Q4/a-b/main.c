#include <stdio.h>
#include <complex.h>
#include "Kerner.h"

int main(){
    int grau = 10;
    complex coeficientes[grau+1];
// observe que poderiamos implementar para qualquer grau a ser inserido pelo usuario
// basta colocar um scanf para scaniar o grau
    for(int i=0; i< grau+1;i++){
        printf("Insira os coeficientes\n");
        scanf("%lf %lf", &coeficientes[i]);
    }
    Kerner(coeficientes,grau);
    return 0;
}