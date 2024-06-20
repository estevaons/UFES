#ifndef arvore_h
#define arvore_h

#include"aluno.h"

typedef struct arv Arvore;

Arvore* arvore_CriaVazia();

Arvore* arvore_Cria(Aluno* al, Arvore* e, Arvore* d);

Arvore* arvore_Libera(Arvore* a);

int arvore_Vazia(Arvore* a);

int arvore_Pertence(Arvore* a, Aluno* al);

void arvore_Imprime(Arvore* a);

int arvore_QtdFolhas(Arvore* a);

int arvore_Ocorrencias(Arvore*a, Aluno* al);

int arvore_altura(Arvore* a);


#endif