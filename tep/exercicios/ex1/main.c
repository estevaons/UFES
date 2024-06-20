#include<stdio.h>
#include"vet.h"

void teste(){
    int tam = 2;
    Vetor *vet1, *vet2;

    vet1 = CriaVetor(tam);
    vet2 = CriaVetor(tam);

    PreencheVetor(vet1);
    PreencheVetor(vet2);

    SomaVetores(vet1, vet2);

    ProdutoVetores(vet1, vet2);

    Desaloca(vet1);
    Desaloca(vet2);
}

int main(){

    teste();
    return 0;
}