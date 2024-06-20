
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct posicao Posicao;

struct lista{
    Posicao *pt_valor;
    struct lista *prox;
};

typedef struct lista Lista;

Lista* Inicia();
void Preenche(Lista *l);
void Printa(Lista* el);
void Desaloca(Lista* el);


#endif