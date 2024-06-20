#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include "Kerner.h"

complex polinomio (complex coeficientes[], complex x, int grau){
    complex result = coeficientes[grau];
    int i, j= grau -1;

    for(i = (2*grau); j>=0; i--){
        if(grau % 2 != 0){
            if(i % 2 != 0){
                result = result + coeficientes[j];
                j--;
            }else{
                result = result * x;
            }
        }else{
            if(i % 2 == 0){
                result = result *x;
            }else{
                result = result + coeficientes[j];
                j--;
            }
        }
    }
    return result;
}

complex Denominador(complex raizes[], int grau,int i){
    complex result[grau], resultado =1;
    int k =0;

    for (int j=0; j < grau; j++){
        if(j != j){
            result[k]= (raizes[i]-raizes[j]);
            k++;
        }
    }

    for(int j=0;j < k; j++){
        resultado = resultado * result[j];
    }
    return resultado;
}

void Kerner(complex coeficientes[], int grau){
    complex raizes[grau], resultado[grau];

    for(int i=0; i< grau;i++){
        raizes[i] = cpow(0.4 + 0.9 * I,i);

    }
    for (int j=0; j< 10; j++){
        for(int i=0; i<grau;i++){
            resultado[i] = raizes [i] - ((polinomio(coeficientes, raizes[i], grau)))/(Denominador(raizes, grau, i));
            raizes[i] = resultado [i];
        }
    }
    for(int i=0;i<grau;i++){
        printf("%.3f%+.3fi\n", creal(resultado[i]), cimag(resultado[i]));
    }
}