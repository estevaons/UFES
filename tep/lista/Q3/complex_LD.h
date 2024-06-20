#ifndef COMPLEXO_LD_H
#define COMPLEXO_LD_H
#include <complex.h>

typedef struct complexold{
    tComplexo_B super;
    long double *info;

}tComplexoLongDouble;

bool Construtor_LongDouble (tComplexoLongDouble ** const me);
bool Destrutor_LongDouble (tComplexoLongDouble * const me);

tComplexoLongDouble *Copia_LongDouble(tComplexoLongDouble const *me);
tComplexoLongDouble * Converte_LongDouble(void * estrutura);
tComplexoLongDouble * SomaComplexosDoVetor_LongDouble(tComplexoLongDouble * const me, unsigned int tam);
tComplexoLongDouble ConstrutorVetor_LD(tComplexoLongDouble ** const me, unsigned int tam);

#endif