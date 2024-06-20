#ifndef VET_H
#define VET_H

typedef struct vet Vetor;

Vetor* CriaVetor(int tamanho);
void PreencheVetor(Vetor *v);
void SomaVetores(Vetor* v1, Vetor* v2);
void ProdutoVetores(Vetor *v1, Vetor *v2);
void Desaloca(Vetor* v);

#endif