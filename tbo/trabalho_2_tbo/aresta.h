#ifndef ARESTA_H_
#define ARESTA_H_

struct aresta{
    double time;
    double distancia;
    double velocidade;
    int origem;
    int destino;
};

typedef struct aresta Aresta;

struct att{
    double time;
    int origem;
    int destino;
    double velocidade;
};

typedef struct att Att;

Aresta* cria_aresta(int origem, int destino, double distancia, double velocidade);

Att* cria_att(double time, int origem, int destino, double velocidade);

#endif