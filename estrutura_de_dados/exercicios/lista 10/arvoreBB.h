#ifndef arvoreBB_h
#define arvoreBB_h

#include"aluno.h"

typedef struct arv Arvore;

Arvore* arvoreBB_Cria();

Arvore* arvoreBB_Busca(Arvore* a, int chave);

Arvore* arvoreBB_Insere(Arvore* a, Aluno* al);

Arvore* arvoreBB_Retira(Arvore* a, int matricula);

Arvore* arvoreBB_Libera(Arvore* a);

int arvore_Vazia(Arvore* a);

void arvoreBB_Imprime(Arvore* a);



#endif