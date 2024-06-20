#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Kerner.h"



tComplexo polinomio (tComplexo coeficientes[], tComplexo x, int grau){
    tComplexo resultado = coeficientes[grau];
    int i;
    int j = grau - 1;

    for(i = (2*grau); j >= 0; i--){
        if(grau % 2 != 0){
            if(i % 2 != 0){
                resultado.re = resultado.re + coeficientes[j].re;
                resultado.im = resultado.im + coeficientes[j].im;
                j--;
            }else{
                resultado = ProdutoComplexos(resultado, x);
            }
        }else{
            if(i % 2 == 0){
                resultado = ProdutoComplexos(resultado, x);
            }else{
                resultado.re = resultado.re + coeficientes[j].re;
                resultado.im = resultado.im + coeficientes[j].im;
                j--;
            }  
        }
        
    }



    return resultado;


}


tComplexo ProdutoComplexos(tComplexo p, tComplexo q){
    tComplexo resultado;
    double a,b,c,d;

    a = p.re * q.re;
    b = p.re * q.im;
    c = p.im * q.re; 
    d = p.im * q.im; 
    d = d * (-1);
    resultado.re = a+d;
    resultado.im = b+c;

    return resultado;
}



tComplexo SubtracaoComplexos(tComplexo p, tComplexo q){
    tComplexo resultado;

    resultado.re = p.re - q.re;
    resultado.im = p.im - q.im;


    return resultado;
}


tComplexo DivisaoComplexos(tComplexo p, tComplexo q){
    tComplexo resultado;
    resultado.re = (((p.re*q.re) + (p.im*q.im))/(q.re*q.re + q.im*q.im));
    resultado.im = ((-(p.im*q.im) + (p.im*q.re))/(q.re*q.re + q.im*q.im));

    return resultado;
}

tComplexo SomaComplexos(tComplexo p, tComplexo q){
    tComplexo soma;
    soma.re = p.re + q.re;
    soma.im = p.im + q.im;

    return soma;

}



tComplexo Power(int i){
    tComplexo a;
    int resto;

    a.re = 0.4;
    a.im = 0.9;

    a.re = pow(a.re, i);
    a.im = pow(a.im, i);

    resto = i % 4;


    if(resto == 2){
        a.im = a.im * (-1);
    }else if(resto == 3){
        a.im = a.im * (-1);
    }

    return a;
}



tComplexo Denominador(tComplexo raizes[], int grau, int i){
    tComplexo resultado[grau];
    tComplexo result;

    result.re = 1;
    result.im = 0;

    int k = 0;
    

    for(int j = 0; j < grau; j++){
        if(i != j){
            resultado[k] = SubtracaoComplexos(raizes[i], raizes[j]);
            k++;
        }
    }

    for(int j = 0; j < k ; j++){
        result = ProdutoComplexos(result, resultado[j]);
    }

    return result;
}





void Kremer(tComplexo coeficientes[], int grau){
    tComplexo raizes[grau], resultado[grau], den, num, fator;
    int i = 0;
    
    for(i = 0; i < grau; i++){
        raizes[i] = Power(i);
    }
    
    
    for (int j = 0; j < 10; j++){
       for(i = 0; i < grau; i++){
           num = polinomio(coeficientes, raizes[i], grau);
           den = Denominador(raizes, grau, i);
           fator = DivisaoComplexos(num, den);
           resultado[i] = SubtracaoComplexos(raizes[i], fator);
           raizes[i] = resultado[i];
       }

    }

    for(i = 0; i < grau; i++){
        if(resultado[i].im > 0){
            printf("%.3lf + %.3fi\n", resultado[i].re, resultado[i].im);
        }else{
            printf("%.3lf %.3fi\n", resultado[i].re, resultado[i].im);
        };
    }
 
 
}