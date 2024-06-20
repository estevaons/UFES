
#ifndef FUNCOES_H
#define FUNCOES_H

struct prim_noh{
    void* pt_valor;
    struct prim_noh *prox;
};

typedef struct prim_noh Prim_noh;

Prim_noh* CriaPonteiro();

void setaValor(Prim_noh *p, void *n);
void Desaloca(Prim_noh *p);

void Printa(Prim_noh* p);

#endif