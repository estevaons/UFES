#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "complex_D.h"


#include <stdlib.h>
#include <stdio.h>



static void Subtracao_Double(tComplexo_D const * me, tComplexo_D const * outro, tComplexo_D const * result);
static long double ModuloComplexo_Double(tComplexo_D const * me);


static void Atribui_Double(tComplexo_D * const me, double re, double im);
static int MaiortComplexo_DoVetor_Double(tComplexo_D * const me, unsigned int tam);
static void Soma_Double(tComplexo_D const * me, tComplexo_D const * outro, tComplexo_D const * result);



bool Construtor_Double(tComplexo_D ** const me){
    Construtor((tComplexo_B**) ((&(*me)->super)));

    (*me)->info = malloc(4 * sizeof(double));

    (*me)->info[0] = 0;
    (*me)->info[1] = 0;
    (*me)->info[2] = 0;
    (*me)->info[3] = 0;

    if(!me){
        return false;
    }else{
        return true;
    }
}

bool Destrutor_Double(tComplexo_D * const me){
    
    Destrutor((tComplexo_B*) &me->super);
    free(me);

    if(!me){
        return true;
    }else{
        return false;
    }
}


tComplexo_D ConstrutorVetor_D(tComplexo_D ** const me, unsigned int tam){
    Construtor((tComplexo_B**) ((&(*me)->super)));

    *me = malloc(tam * sizeof(tComplexo_D));
    

    for(int i = 0; i < tam; i++){
        (*me)[i].info = malloc(4 * sizeof(double));
        for(int j = 0; j < 4; j++){
            (*me)[i].info[j] = 0;
        }
    }

    
}


static void Atribui_Double(tComplexo_D * const me, double re, double im){
    me->info[0] = re;
    me->info[1] = im;
}

tComplexo_D *Copia_D(tComplexo_D const * me){
    tComplexo_D *a;

    Construtor_D(&a);
    
    a->super.vptr->Atribui_(a, me->info[0], me->info[1]);

    return a;
}


static void Soma_Double(tComplexo_D const * me, tComplexo_D const * outro, tComplexo_D const * result){
     double x, y, z, w;

     x = me->info[0];
     y = me->info[1];
     z = outro->info[0];
     w = outro->info[1];


     Atribui_(result, x+z, y+w);
}

static void Subtracao_Double(tComplexo_D const * me, tComplexo_D const * outro, tComplexo_D const * result){
    double x, y, z, w;

     x = me->info[0];
     y = me->info[1];
     z = outro->info[0];
     w = outro->info[1];


     Atribui_(result, x-z, y-w);
}


static long double ModuloComplexo_Double(tComplexo_D const * me){
    long double Modulo;
    double x, y;

    x = pow(me->info[0], 2);
    y = pow(me->info[1], 2);

    Modulo = sqrt(x+y);

    return Modulo;
}

tComplexo_D * Converte_D(void * estrutura){
    double x, y;
    tComplexo_D *a;

    x = (double)(*estrutura).info[0];
    y = (double)(*estrutura).info[1];

    Construtor_D(&a);

    Atribui_(a, x, y);

    return a;
}

static int MaiortComplexo_DoVetor_Double(tComplexo_D * const me, unsigned int tam){
    int posicao;
    double mr = 0, mi = 0;


    for(int i = 0; i < tam; i++){
        if(me[i].info[0] >= mr && me[i].info[1] >= mi){
            posicao = i;
            mr = me[i].info[0];
            mi = me[i].info[1];
        }
    }

    return posicao;
}

tComplexo_D * SomaComplexosDoVetor(tComplexo_D * const me, unsigned int tam){
    tComplexo_D * result;
    Construtor_D(&result);

    for(int i = 0; i < tam; i+=2){
        for(int j = 0; j < 2; j++){
            result[i].info[j] = me[i].info[j] + me[i+1].info[j];
        }
    }

    return result;
}