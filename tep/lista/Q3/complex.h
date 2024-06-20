#ifndef COMPLEXO_H
#define COMPLEXO_H

struct Tabela_Virtual;

typedef struct Complexo{
    struct Tabela_Virtual const * vptr;
}tComplexo_B;

struct Tabela_Virtual{
    
    void (* Atribui_) (tComplexo_B * const me, char re, char im);
    int  (* MaiorComplexoDoVetor_)(tComplexo_B * const me, unsigned int tam);
    void (*Soma_)(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result);
    void (*Subtracao_)(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result);
    long double (*ModuloComplexo_)(tComplexo_B const * me);

};

void Construtor(tComplexo_B ** const me);
void Destrutor(tComplexo_B * const me);



// funções static, só podem ser vistas nesse arquivo


static inline void Subtracao_(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result){
    (*me->vptr->Subtracao_)(me, outro, result);
}

static inline void Atribui(tComplexo_B * const me, char re, char im){
    (*me->vptr->Atribui_)(me, re, im);
}

static inline long double ModuloComplexo(tComplexo_B const * me){
    return(*me->vptr->ModuloComplexo_)(me);
}

static inline int MaiorComplexoDoVetor(tComplexo_B * const me, unsigned int tam){
    return(*me->vptr->MaiorComplexoDoVetor_)(me, tam);
}

static inline void Soma(tComplexo_B const * me, tComplexo_B const * outro, tComplexo_B const * result){
    (*me->vptr->Soma_)(me, outro, result);
}





#endif
