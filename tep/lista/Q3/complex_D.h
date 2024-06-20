#ifndef COMPLEXO_D_H
#define COMPLEXO_D_H
#include "complex.h"

typedef struct Complexod{
    tComplexo_B super;
    double *info;
}tComplexo_D;

bool Construtor_Double(tComplexo_D ** const me);
bool Destrutor_Double(tComplexo_D * const me);

tComplexo_D * SomaComplexosDoVetor(tComplexo_D * const me, unsigned int tam);
tComplexo_D ConstrutorVetor_Double(tComplexo_D ** const me, unsigned int tam);

tComplexo_D *Copia_Double(tComplexo_D const * me);
tComplexo_D * Converte_Double(void * estrutura);

#endif