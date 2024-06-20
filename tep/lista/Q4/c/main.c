
#include <stdio.h>
#include "Kerner.h"

int main(){
    int grau = 3;
    tComplexo coeficientes[grau+1];
    
    /* x3 − 3x2 + 3x − 5 =  0 */
    coeficientes[3].re = 1.0; 
    coeficientes[3].im = 0;
    coeficientes[2].re = -3.0; 
    coeficientes[2].im = 0;
    coeficientes[1].re = 3.0;
    coeficientes[1].im = 0;
    coeficientes[0].re = -5.0; 
    coeficientes[0].im = 0;


    Kremer(coeficientes, grau);
    return 0;
}