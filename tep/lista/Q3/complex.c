
#include <stdbool.h>
#include <assert.h>
#include "complex.h"
#include <stdlib.h>
#include <stdio.h>


void Construtor(tComplexo_B ** const me){
    static struct Tabela_Virtual const vtbl = {
        &Atribui_,
        &MaiorComplexoDoVetor_,
        &Soma_,
        &Subtracao_,
        &ModuloComplexo_
    };

    *me = (tComplexo_B *)malloc(sizeof(tComplexo_B));
    (*me)->vptr = &vtbl;

}

void Destrutor(tComplexo_B * const me){
    free(me);
}


// funções statics, só podem ser vistas nesse arquivo

static int MaiorComplexoDoVetor_(tComplexo_B * const me, unsigned int tam){
    assert(0);
}

static void Atribui_(tComplexo_B * const me, char re, char im){
    assert(0);
}

static void Subtracao_(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result){
    assert(0);
}



static void Soma_(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result){
    assert(0);
}

static long double ModuloComplexo_(tComplexo_B const * me){
    assert(0);
}

