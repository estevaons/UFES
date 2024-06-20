#include "util.h"
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define ERROR -1
#define SUCCESS 0

#define EPSILON 0.000001

// Funcao auxiliar para converter uma string para minusculo
// Entrada: str - string a ser convertida
// Saida: void
void STR_toLower(char* str){
    int i = 0;
    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }
}

// Funcao que le o arquivo index e retorna a arvore
// Entrada: arquivo - caminho do arquivo index.txt
//          nPaginas - ponteiro para o numero de paginas
// Saida: Arvore rubro negra com as paginas
RBT* LePaginas(char* arquivo, int* nPaginas){
    
    // Cria o caminho para o arquivo index.txt
    char* indexPath = malloc((strlen(arquivo) + strlen("index.txt") + 1) * sizeof(char));
    strcpy(indexPath, arquivo);
    strcat(indexPath, "index.txt");

    // Abre o arquivo index.txt
    FILE* fpIndex = fopen(indexPath,"r");

    // Verifica se o arquivo index.txt foi aberto corretamente
    if (fpIndex == NULL) {
        printf("Erro: index.txt nao encontrado.\n");
        exit(ERROR);
    }

    // Buffer para leitura
    size_t bufferSize = 64;
    char * buffer = (char*) malloc(bufferSize * sizeof(char));

    RBT* paginas = NULL;
    int i = 0;

    // Le o arquivo index.txt
    while (!feof(fpIndex)) {
        int qtdLida = getline(&buffer, &bufferSize, fpIndex);
        
        // Obtem o nome da pagina atual
        char* token = strtok(buffer,"\n");
        buffer = token;

        // Cria a pagina
        Pagina* p = CriaPagina(buffer);

        // Incrementa o numero de paginas
        paginas = RBT_insert(paginas, GetNomePagina(p), p, false);
        i++;
    }

    // Atualiza o numero de paginas
    *nPaginas = i;

    // Fecha o arquivo index.txt
    fclose(fpIndex);
    
    // Libera a memoria alocada
    free(buffer);
    free(indexPath);

    return paginas;
}

// Funcao que le o arquivo stopwords e retorna a arvore
// Entrada: arquivo - caminho do arquivo stopwords.txt
//          nStopWords - ponteiro para o numero de stopwords
// Saida: Arvore rubro negra com as stopwords
RBT* LeStopWords(char* arquivo, int* nStopWords){

    // Cria o caminho para o arquivo stopwords.txt
    char* stopwordsPath = malloc((strlen(arquivo) + strlen("stopwords.txt") + 1) * sizeof(char));
    strcpy(stopwordsPath, arquivo);
    strcat(stopwordsPath, "stopwords.txt");

    // Abre o arquivo stopwords.txt
    FILE* fpstopwords = fopen(stopwordsPath,"r");

    // Verifica se o arquivo stopwords.txt foi aberto corretamente
    if (fpstopwords == NULL) {
        printf("Erro: stopwords.txt nao encontrado.\n");
        exit(ERROR);
    }

    // Buffer para leitura
    size_t bufferSize = 64;
    char * buffer = (char*) malloc(bufferSize * sizeof(char));

    RBT* stopwords = NULL;
    int i = 0;
    
    // Le o arquivo stopwords.txt
    while (!feof(fpstopwords)) {
        int qtdLida = getline(&buffer, &bufferSize, fpstopwords);
        
        // Obtem a stop word atual
        char* pt = strtok(buffer,"\n");
        buffer = pt;

        // Converte a stop word para minusculo
        STR_toLower(buffer);

        // Insere a stop word na arvore
        stopwords = RBT_insert(stopwords, buffer, (void*)buffer, true);

        // Incrementa o numero de stopwords
        i++;
    }

    // Atualiza o numero de stopwords
    *nStopWords = i;


    // Fecha o arquivo stopwords.txt
    fclose(fpstopwords);

    // Libera a memoria alocada
    free(buffer);
    free(stopwordsPath);

    return stopwords;
}

// Funcao que le o arquivo graph.txt e atualiza os links da lista de paginas
// Entrada: paginas - arvore rubro negra com as paginas
//          arquivo - caminho do arquivo graph.txt
//          nPaginas - numero de paginas
void LeGraphs(RBT* paginas, char* arquivo, int nPaginas){
    // Cria o caminho para o arquivo graphs.txt
    char* graphsPath = malloc((strlen(arquivo) + strlen("graph.txt") + 1) * sizeof(char));
    strcpy(graphsPath, arquivo);
    strcat(graphsPath, "graph.txt");

    // Abre o arquivo graphs.txt
    FILE* fpGraphs = fopen(graphsPath,"r");

    // Verifica se o arquivo graphs.txt foi aberto corretamente
    if (fpGraphs == NULL) {
        printf("Erro: graph.txt nao encontrado.\n");
        exit(ERROR);
    }

    // Buffer para leitura
    size_t bufferSize = 64;
    char * buffer = (char*) malloc(bufferSize * sizeof(char));

    // Le o arquivo graphs.txt
    while (!feof(fpGraphs)) {
        int qtdLida = getline(&buffer, &bufferSize, fpGraphs);
        if (qtdLida == -1) break;
        // Obtem o nome da pagina atual
        char* token = strtok(buffer, "\n");

        // Obtem a pagina atual
        token = strtok(token, " ");

        // Obtem a pagina atual
        Pagina* origem = (Pagina*)search(paginas, token);

        // Obtem o numero de links da pagina atual
        token = strtok(NULL," ");

        // Atualiza o numero de links da pagina atual
        SetNLinksPagina(origem, atoi(token));

        //Inicializa o PR com 1/nPaginas
        SetPRPagina(origem, ((double)1.0/nPaginas), 0);

        // Obtem as paginas que a pagina atual aponta
        while((token = strtok(NULL, " ")) != NULL){
            // Obtem a pagina atual
            Pagina* destino = (Pagina*)search(paginas, token);
            
            // Insere a pagina atual na lista de paginas que a pagina incial aponta
            SetListaPagina(origem, destino);
        }
        
    }

    // Fecha o arquivo graphs.txt
    fclose(fpGraphs);
    
    // Libera a memoria alocada
    free(buffer);
    free(graphsPath);
}

// Funcao que le os termos de uma pagina e preenche os termos
// Entrada: termos - arvore rubro negra com os termos
//          stopWords - arvore rubro negra com as stop words
//          p - pagina atual
//          diretorio - caminho do diretorio das paginas
// Saida: Arvore rubro negra com os termos
RBT* Indexador(RBT* termos, RBT* stopWords, Pagina* p, char* diretorio){
    // Cria o caminho para a pagina atual
    char* paginaPath = malloc((strlen(diretorio) + strlen(GetNomePagina(p)) + 1) * sizeof(char));
    strcpy(paginaPath, diretorio);
    strcat(paginaPath, GetNomePagina(p));

    // Abre o arquivo da pagina
    FILE* fpPagina = fopen(paginaPath, "r");

    // Verifica se o arquivo da pagina foi aberto corretamente
    if (fpPagina == NULL) {
        printf("Erro: pagina.txt nao encontrado.\n");
        exit(ERROR);
    }

    // Buffer para leitura
    size_t bufferSize = 64;
    char * buffer = (char*) malloc(bufferSize * sizeof(char));

    int i = 0;

    // Le o arquivo da pagina
    while (!feof(fpPagina)) {
        int qtdLida = getline(&buffer, &bufferSize, fpPagina);
        
        char* token = strtok(buffer,"\n");
        buffer = token;

        token = strtok(buffer, " ");
        while(token != NULL){
            // Converte o token para minusculo
            STR_toLower(token);

            // Se o termo atual nao for uma stop word
            if(search(stopWords, token) == NULL){
                
                // Busca a lista de paginas que contem o termo
                ListaP* lista;
                lista = (ListaP*)search(termos, token);

                // Se a lista estiver vazia, insere a pagina
                if(lista == NULL){
                    lista = InserePaginaLista(lista, p);
                    termos = RBT_insert(termos, token, lista, false);
                    i++;
                }
                // Se a pagina nao estiver na lista, insere
                else if(GetPaginaLista(lista) != p){
                    lista = InserePaginaLista(lista, p);
                    termos = RBT_insert(termos, token, lista, false);
                    i++;
                }
            }

            // Avanca para o proximo termo
            token = strtok(NULL, " ");
        }

        
    }

    // Fecha o arquivo da pagina
    fclose(fpPagina);
    
    // Libera a memoria alocada
    free(buffer);
    free(paginaPath);

    return termos;
    
}

// Funcao que le os arquivos das paginas e preenche a arvore de termos
// Entrada: termos - arvore rubro negra com os termos
//          paginas - arvore rubro negra com as paginas
//          stopWords - arvore rubro negra com as stop words
//          diretorio - caminho do diretorio das paginas
// Saida: Arvore rubro negra com os termos
RBT* RecIndexador(RBT* termos, RBT* paginas, RBT* stopWords, char* diretorio) {
    if (paginas == NULL) return termos;
    termos = RecIndexador(termos, GetLeft(paginas), stopWords, diretorio);
    termos = Indexador(termos, stopWords, (Pagina*)GetValue(paginas), diretorio);
    termos = RecIndexador(termos, GetRight(paginas), stopWords, diretorio);

    return termos;
}

// Funcao que calcula o PageRank de uma pagina
// Entrada: p - pagina atual
//         nPaginas - numero de paginas
//         impar - indica se eh impar
// Saida: PageRank atual
double CalculaPageRank(Pagina* p, int nPaginas, int impar){
    double pr = 0;
    if(impar == 1){
        if(GetNLinksPagina(p) == 0){
            pr = (0.15 / nPaginas) + (0.85 * GetPRPagina(p, 0));
            ListaP* l = GetListaPagina(p);
            double aux = 0;
            while(l != NULL){
                aux += (GetPRPagina(GetPaginaLista(l), 0) / GetNLinksPagina(GetPaginaLista(l)));
                l = GetProxLista(l);
            }
            pr += (aux * 0.85);
        }
        else{
            pr = (0.15 / nPaginas);
            ListaP* l = GetListaPagina(p);
            double aux = 0;
            while(l != NULL){
                aux += (GetPRPagina(GetPaginaLista(l), 0) / GetNLinksPagina(GetPaginaLista(l)));
                l = GetProxLista(l);
            }
            pr += (aux * 0.85);
        }
        SetPRPagina(p, pr, 1);
    }
    else{
        if(GetNLinksPagina(p) == 0){
            pr = (0.15 / nPaginas) + (0.85 * GetPRPagina(p, 1));
            ListaP* l = GetListaPagina(p);
            double aux = 0;
            while(l != NULL){
                aux += (GetPRPagina(GetPaginaLista(l), 1) / GetNLinksPagina(GetPaginaLista(l)));
                l = GetProxLista(l);
            }
            pr += (aux * 0.85);
        }
        else{
            pr = (0.15 / nPaginas);
            ListaP* l = GetListaPagina(p);
            double aux = 0;
            while(l != NULL){
                aux += (GetPRPagina(GetPaginaLista(l), 1) / GetNLinksPagina(GetPaginaLista(l)));
                l = GetProxLista(l);
            }
            pr += (aux * 0.85);
        }
        SetPRPagina(p, pr, 0);
    }
    return fabs(GetPRPagina(p, 0) - GetPRPagina(p, 1));
}



double RecPR(RBT* paginas, int nPaginas, double erro, int impar) {
    if (paginas == NULL) return erro;
    RecPR(GetLeft(paginas), nPaginas, erro, impar);
    erro += CalculaPageRank((Pagina*)GetValue(paginas), nPaginas, impar);
    RecPR(GetRight(paginas), nPaginas, erro, impar);

    return erro;
}

// Funcao que executa o power method para calcular o page rank das paginas
// Entrada: paginas - arvore rubro negra com as paginas
//         nPaginas - numero de paginas
// Saida: int - posicao final do page rank no vetor de page rank
int PowerMethod(RBT* paginas, int nPaginas){
    int i = 1;
    double erro = 0;

    // Enquanto o erro for maior que o epsilon, calcula o page rank recursivamente
    while((RecPR(paginas, nPaginas, erro, (i % 2)) / nPaginas) >= EPSILON){
        erro = 0;
        i++;
    }
    i++;
    return (i % 2);
}