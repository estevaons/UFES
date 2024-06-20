#ifndef COMPLEXO_GEN_H
#define COMPLEXO_GEN_H
#include "complex.h"

typedef struct tComplexo_Generic{
    tComplexo_B super;
    void * info;
}tComplexo_Generic;

bool Construtor_Generic(tComplexo_Generic ** const me);
bool Destrutor_Generic (tComplexo_Generic * const me);


tComplexo_Generic * SomaComplexosDoVetor_Generic(tComplexo_Generic * const me, unsigned int tam);
tComplexo_Generic ConstrutorVetor_Generic(tComplexo_Generic ** const me, unsigned int tam);

tComplexo_Generic *Copia_Generic(tComplexo_Generic const *me);
tComplexo_Generic * Converte_Generic(void * estrutura);

#endif