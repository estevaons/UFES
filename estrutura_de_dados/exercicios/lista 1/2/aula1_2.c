#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void calc_esfera(float r, float* area, float* volume){
    (*area) = 4 * (3.14) * (r*r);
    (*volume) = (4 * (3.14) * (r*r*r))/3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    float delta = 0;

    delta = (b*b) - 4 * a * c;

    if(delta>0){ // portanto temos duas raizes reais
        *x1 = ((-1*b) + sqrtf(delta))/2*a;
        *x2 = ((-1*b) - sqrtf(delta))/2*a;
        return 1;
    }
    if(delta == 0){// portanto temos uma raiz real
        *x1 = ((-1*b) + sqrtf(delta))/2*a;
        return 2;
    }

    if(delta < 0){// nesse caso não temos raizes reais
        return 3;
    } 

}



int pares (int n, int* vet){
    int i=0,cont=0;

    for(i=0;i<n;i++){
        if(vet[i]%2 == 0){
            cont++;
        }
    }
    return cont;
}

void inverte (int n, int* vet){
    int *vetAux;
    int tam = n;
    int i=0;
    int j=0;
    vetAux = (int*) malloc(sizeof(int)*n);
    

    for(i=n-1;i>=0;i--){
        vetAux[j] = vet[i];
        j++;
    }

    for(i=n-1;i>=0;i--){
        vet[i] = vetAux[i];
    }


 
    free(vetAux);

}


double avalia (double* poli, int grau, double x){
    double result = 0;
    double *polinomioAux;
    polinomioAux = (double*) malloc(sizeof(double)*grau);
    int j=0;

    for(int i= grau; i>=0; i--){
        polinomioAux[j] = poli[i] * pow(x,i);
        j++;
    }

    for(int i=0; i<grau+1;i++){
        result = result + polinomioAux[i];
    }

    return result;
    free(polinomioAux);
}




// main para testar 2.1
// int main(){
//     float r=0;
//     float area,volume;

//     printf("informe o raio da esfera:\n");
//     scanf("%f",&r);
//     calc_esfera(r,&area,&volume);

//     printf("a area da esfera eh: %.2f\n", area);
//     printf("o volume da esfera eh: %.2f\n", volume);

//     return 0;
// }

// main para testar 2.2
// int main(){

//     float a,b,c;
//     float raiz_x1,raiz_x2;
//     int verificaDelta;

//     printf("informe os coeficientes de uma equação do segundo grau (a,b,c) respectivamente:\n");
//     scanf("%f%f%f",&a,&b,&c);

//     verificaDelta = raizes(a,b,c,&raiz_x1,&raiz_x2);
    
//     if(verificaDelta == 1){
//         printf("esta equacao possui 2 raizes reais sendo elas x1= %f e x2= %f\n",raiz_x1,raiz_x2);
//     }
//     if(verificaDelta == 2){
//         printf("esta equcao possui 1 raiz real sendo ela x1= %f\n", raiz_x1);
//     }
//     if(verificaDelta == 3){
//         printf("esta equacao n possui raiz real\n");
//     }


//     return 0;
// }

// main para testar 2.3
// int main(){
//     int tam = 0;
//     int *vet;
//     int i=0,qtd=0;

//     printf("informe o tamanho do vetor:\n");
//     scanf("%d",&tam);
//     printf("informe os numeros do vetor: ");

//     vet = (int *) malloc(sizeof(int)*tam);

//     for(i=0;i<tam;i++){
//         scanf("%d",&vet[i]);
//     }

//     qtd = pares(tam,vet);
//     printf("a quantidade de numeros pares no vetor eh: %d\n",qtd);

//     free(vet);

//     return 0;
// }

//main para testar 2.4

// int main(){
//     int tam;
//     int *vet;
//     int i=0;

//     printf("informe o tamnho do vetor: ");
//     scanf("%d",&tam);

//     vet = (int *) malloc(sizeof(int)*tam);

//     printf("informe os numeros do vetor:\n");

//     for(i=0;i<tam;i++){
//         scanf("%d",&vet[i]);
//     }

//     inverte(tam,vet);

//     printf("imprimindo vetor invertido\n");
//     for(i=0;i<tam;i++){
//         printf("%d ", vet[i]);
//     }

//     free(vet);
//     return 0;
// }


//main para testar 2.5

int main(){

    int grau;
    double *poli;
    double x;
    double resultPol;


    printf("informe o grau do polinomio: ");
    scanf("%d", &grau);

    poli = (double *)malloc(sizeof(double)*(grau+1));

    printf("informe os coeficientes do polinomio: ");

    // 3x²+2x+12   --- {12,2,3}
    for(int i=grau;i>=0;i--){
        scanf("%lf", &poli[i]);
    }

    printf("informe o valor de x: ");
    scanf("%lf", &x);

    resultPol = avalia(poli,grau,x);

    printf("o resultado eh: %.2lf\n",resultPol);

    return 0;
}