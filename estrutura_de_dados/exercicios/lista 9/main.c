#include<stdio.h>
#include"arvore.h"



int main(){

    Aluno* al1 = iniciaAluno("maria",13214,6.65);
    Aluno* al2 = iniciaAluno("florinda",16546,7.8);
    Aluno* al3 = iniciaAluno("carlos",4325,4.3);
    Aluno* al4 = iniciaAluno("miguel",4325,9.4);
    Aluno* al5 = iniciaAluno("mariana",6547,8.3);
    Aluno* al6 = iniciaAluno("fabricia",23145,5.5);
    Aluno* al7 = iniciaAluno("jose",1231,4.5); // ALUNO NAO PERTENCE A ARVORE


    Arvore* a = arvore_Cria(al1,
        arvore_Cria(al2,
            arvore_CriaVazia(),
                arvore_Cria(al4, arvore_CriaVazia(),
                    arvore_CriaVazia()
                )
        ),arvore_Cria(al3,
            arvore_Cria(al5, arvore_CriaVazia(),
                arvore_CriaVazia()
            ),
            arvore_Cria(al6, arvore_CriaVazia(),
                arvore_CriaVazia()
            )
        )
    );

    arvore_Imprime(a);

    printf("\no aluno:\n");
    imprimeAluno(al1);
    printf("pertence a arvore?: ");
    if(arvore_Pertence(a,al1)){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    printf("o aluno:");
    imprimeAluno(al7);
    printf("pertence a arvore?: ");
    if(arvore_Pertence(a,al7)){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    int numFolhas = arvore_QtdFolhas(a);
    printf("o numero de folhas da arvore eh: %d\n",numFolhas);



    int numOcorrencias = arvore_Ocorrencias(a,al2);
    printf("o numero de vezes que o aluno:\n");
    imprimeAluno(al2);
    printf("aparece na arvore eh: %d\n",numOcorrencias);


    int alturaDaArvore = arvore_altura(a);

    printf("a altura da arvore eh: %d\n",alturaDaArvore);


    arvore_Libera(a);
    liberaAluno(al1);
    liberaAluno(al2);
    liberaAluno(al3);
    liberaAluno(al4);
    liberaAluno(al5);
    liberaAluno(al6);
    liberaAluno(al7);

    return 0;
}