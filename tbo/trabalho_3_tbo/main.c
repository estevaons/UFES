#include <string.h>
#include <stdlib.h>

#include "util.h"
#include "RBT.h"

#define ERROR -1
#define SUCCESS 0

int main(int argc, char* argv[]) {

    // Verifica os argumentos
    if (argc != 2) {
        printf("Erro: argumentos invalidos\n");
        return ERROR;
    }

    // Numero de paginas total
    int nPaginas = 0;

    // Le as paginas
    RBT* paginas = LePaginas(argv[1], &nPaginas);

    // Numero de stop words
    int nStopWords = 0;

    // Le as stop words
    RBT* stopWords = LeStopWords(argv[1], &nStopWords);

    // Le o arquivo graph.txt
    LeGraphs(paginas, argv[1], nPaginas);

    // Monta o caminho para a pasta pages
    char* pages = malloc((strlen(argv[1]) + strlen("pages/") + 1)* sizeof(char));
    strcpy(pages, argv[1]);
    strcat(pages, "pages/");

    // Inicia o indexador
    RBT* termos = NULL;
    termos = RecIndexador(termos, paginas, stopWords, pages);

    // char palavra[100];
    // scanf("%s",palavra);
    // ListaP* listaPalavras = (ListaP*)search(termos,palavra);
    // imprimeLista(listaPalavras);

    // Executa o power method
    int posicao = PowerMethod(paginas, nPaginas);
    
    // Libera a memoria
    RBT_destroy(termos, LiberaLista);
    RBT_destroy(paginas, LiberaPagina);
    RBT_destroy(stopWords, NULL);
    free(pages);
    
    return SUCCESS;
}