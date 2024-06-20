#ifndef UTIL_H
#define UTIL_H

#include "pagina.h"
#include "RBT.h"

RBT* LePaginas(char* arquivo, int* nPaginas);

RBT* LeStopWords(char* arquivo, int* nStopWords);

void LeGraphs(RBT* paginas, char* arquivo, int nPaginas);

RBT* Indexador(RBT* termos, RBT* stopWords, Pagina* p, char* diretorio);

RBT* RecIndexador(RBT* termos, RBT* paginas, RBT* stopWords, char* diretorio);

int PowerMethod(RBT* paginas, int nPaginas);

#endif