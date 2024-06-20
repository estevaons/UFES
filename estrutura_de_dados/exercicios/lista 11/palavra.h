#ifndef palavra_h
#define palavra_h


typedef struct palavra Palavra;

Palavra* inicia_palavra(char* str);

char* retornaString(Palavra* palavra);

void atualizaOcorrencias(Palavra* palavra);

int retornaOcorrencias(Palavra* palavra);

Palavra* inserePalavraNaLista(Palavra* lista, Palavra* palavra);

Palavra* buscaPalavra(Palavra* palavra, char* str);

int contaPalavrasNaLista(Palavra* palavra);

void imprimeLista(Palavra* palavra);

void liberaListaDePalavra(Palavra* palavra);

#endif