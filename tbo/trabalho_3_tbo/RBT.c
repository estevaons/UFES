#include "RBT.h"
#include <string.h>
#include "pagina.h"
#include "util.h"

// Definicoes para a arvore rubro-negra
#define RED true
#define BLACK false

// Estrutura generica para a arvore rubro-negra
struct node {
    char* key;
    void* val;
    bool color;
    RBT *l, *r;
};

// Cria um novo no
// Entrada:     char* key - Chave do no
//              void* val - Valor do no
//              bool color - Cor do no
//              bool isStopWord - Indica se o no eh uma stop word
// Saida:       RBT* - Ponteiro para o no criado
RBT* create_node(char* key, void* val, bool color, bool isStopWord) {
    RBT* n = (RBT*) malloc(sizeof(RBT));
    n->key = strdup(key);
    if(isStopWord) n->val = (void*)n->key;
    else n->val = val;
    n->color = color;
    n->l = NULL;
    n->r = NULL;
    return n;
}

// Funcao que compara duas chaves
// Entrada:     char* a - Primeira chave
//              char* b - Segunda chave
// Saida:       int - Resultado da comparacao
int compare(char* a, char* b) {
    int r = strcmp(a, b);
    return r;
}

// Funcao que retorna se um no eh vermelho
// Entrada:     RBT* x - Ponteiro para o no
// Saida:       bool - Indica se o no eh vermelho
bool is_red(RBT *x) {
    if (x == NULL) return BLACK;
    return x->color; //RED == true
}

// Funcao de rotacao para a esquerda
// Entrada:     RBT* h - Ponteiro para o no
// Saida:       RBT* - Ponteiro para o no rotacionado
RBT* rotate_left(RBT *h) {
    RBT *x = h->r;
    h->r = x->l;
    x->l = h;
    x->color = x->l->color;
    x->l->color = RED;
    return x;
}

// Funcao de rotacao para a direita
// Entrada:     RBT* h - Ponteiro para o no
// Saida:       RBT* - Ponteiro para o no rotacionado
RBT* rotate_right(RBT *h) {
    RBT *x = h->l;
    h->l = x->r;
    x->r = h;
    x->color = x->r->color;
    x->r->color = RED;
    return x;
}

// Funcao que troca as cores de um no e seus filhos
// Entrada:     RBT* h - Ponteiro para o no
// Saida:       void
void flip_colors(RBT *h) {
    h->color = RED;
    h->l->color = BLACK;
    h->r->color = BLACK;
}

// Funcao que insere um no na arvore rubro-negra
// Entrada:     RBT* h - Ponteiro para o no
//              char* key - Chave do no
//              void* val - Valor do no
//              bool isStopWord - Indica se o no eh uma stop word
// Saida:       RBT* - Ponteiro para o no inserido
RBT* RBT_insert(RBT *h, char* key, void* val, bool isStopWord) {
    // Insert at bottom and color it red.
    if (h == NULL) { return create_node(key, val, RED, isStopWord); }
    int cmp = compare(key, h->key);
    if (cmp < 0) { h->l = RBT_insert(h->l, key, val, isStopWord); }
    else if (cmp > 0) { h->r = RBT_insert(h->r, key, val, isStopWord); }
    else /*cmp == 0*/ { h->val = val; }
    // Lean left.
    if (is_red(h->r) && !is_red(h->l)) { h = rotate_left(h); }
    // Balance 4-node.
    if (is_red(h->l) && is_red(h->l->l)) { h = rotate_right(h); }
    // Split 4-node.
    if (is_red(h->l) && is_red(h->r)) { flip_colors(h); }
    return h;
}

// Funcao que busca um no na arvore rubro-negra
// Entrada:     RBT* n - Ponteiro para o no
//              char* key - Chave do no
// Saida:       void* - Valor do no
void* search(RBT *n, char* key) {
    while (n != NULL) {
        int cmp;
        cmp = compare(key, n->key);
        if (cmp < 0) n = n->l;
        else if (cmp > 0) n = n->r;
        else return n->val;
    }
    return NULL;
}

// Funcao que destroi a arvore rubro-negra
// Entrada:     RBT* n - Ponteiro para o no
//              void (*Libera) (void*) - Ponteiro para funcao que libera o valor do no
// Saida:       void
void RBT_destroy(RBT* n, void (*Libera) (void*)) {
    if (n == NULL) return;
    RBT_destroy(n->l, Libera);
    RBT_destroy(n->r, Libera);
    free(n->key);
    if(Libera != NULL) Libera(n->val);
    free(n);
}

// Temporario
void RBT_print(RBT* n, int i) {
    if (n == NULL) return;
    RBT_print(n->l, i);
    printf("%s %.8lf\n", n->key,  GetPRPagina((Pagina*)n->val, i));
    RBT_print(n->r, i);
}

// Funcao que retorna o filho esquerdo de um no
// Entrada:     RBT* n - Ponteiro para o no
// Saida:       RBT* - Ponteiro para o filho esquerdo
RBT* GetLeft(RBT* n) {
    return n->l;
}

// Funcao que retorna o filho direito de um no
// Entrada:     RBT* n - Ponteiro para o no
// Saida:       RBT* - Ponteiro para o filho direito
RBT* GetRight(RBT* n) {
    return n->r;
}

// Funcao que retorna o valor de um no
// Entrada:     RBT* n - Ponteiro para o no
// Saida:       void* - Valor do no
void* GetValue(RBT* n) {
    return n->val;
}


void tempPrint(RBT* n) {
    if (n == NULL) return;
    tempPrint(n->l);
    printf("%s: %.8lf %.8lf\n",GetNomePagina((Pagina*)n->val),GetPRPagina((Pagina*)n->val, 0), GetPRPagina((Pagina*)n->val, 1));
    tempPrint(n->r);
}