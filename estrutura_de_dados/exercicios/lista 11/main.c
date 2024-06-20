#include<stdio.h>
#include<stdlib.h>
#include"hash.h"
#include<ctype.h> // para usar a função isalpha

#define tamTab 127
#define nPal 64

    int le_palavra(FILE* arq, char* string){
        int i =0;
        int c;

        while ((c = fgetc(arq))!= EOF){
            if(isalpha(c)){
                break;
            }
        }
        if (c == EOF){
            return 0;
        }else {
            string[i++]=c;
        }
        while ((i<nPal-1)&& (c= fgetc(arq)) != EOF && isalpha(c)){
            string[i++] = c;
        }
        string[i] = '\0';
        return i;
    }

    int main(){
        FILE* arq;
        Hash* tabela;
        char string[nPal];

        arq = fopen("entrada.txt","r");

        tabela = inicia_Hash(tamTab);

        while(le_palavra(arq,string)){
            Palavra* p = acessa(tabela,string);
            atualizaOcorrencias(p);
        }

        imprimeHash(tabela);

        liberaHash(tabela);

        fclose(arq);

        return 0;

    }