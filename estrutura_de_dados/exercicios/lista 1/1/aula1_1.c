#include<stdio.h>

int main(){
    int num1,num2,num3,num4;
    int *pNum1,*pNum2,*pNum3,*pNum4;

    printf("Informe quatro numeros inteiros positivos:\n");
    scanf("%d%d%d%d", &num1,&num2,&num3,&num4);


    pNum1 = &num1;
    pNum2 = &num2; 
    pNum3 = &num3; 
    pNum4 = &num4;


    (*pNum1) *= 2;
    (*pNum2) *= 2;
    (*pNum3) *= 2;
    (*pNum4) *= 2;

    printf("O dobro dos valores informados valem respectivamente: %d %d %d %d\n",num1,num2,num3,num4);


    return 0;
}