#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
    char* nome;
    int matricula;
    float p1,p2,p3;
};

typedef struct aluno Aluno;

char * leNome(void){
    char nome[100];
    scanf(" %99[^\n]" ,nome);

    return strdup(nome);
}


void imprimeDados(int n, Aluno** turma){
    for(int i=0;i<n;i++){
        printf("nome: %s",turma[i]->nome);
        printf(" matricula: %d", turma[i]->matricula);
        printf(" nota p1: %.2f",turma[i]->p1);
        printf(" nota p2: %.2f",turma[i]->p2);
        printf(" nota p3: %.2f",turma[i]->p3);
        printf("\n");
    }
}


void imprime_aprovados (int n, Aluno** turma){
    float media = 0;
    for(int i=0;i<n;i++){
        media = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
        if(media>=5){
            printf("aluno: %s\n",turma[i]->nome);
        }
        media=0;
    }
}


float media_turma (int n, Aluno** turma){
    float media[n];
    float mediaTurma=0;
    for(int i=0;i<n;i++){
        media[i] = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3;
    }

    for(int i=0;i<n;i++){
        mediaTurma += media[i];
    }
    return (mediaTurma/n);
}


int main(){
    int n;
    printf("numero de alunos da turma eh: ");
    scanf("%d",&n);

    Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));

    for(int i=0;i<n;i++){
        turma[i] = (Aluno*)malloc(sizeof(Aluno));

        printf("nome do aluno: ");
        turma[i]->nome = leNome();

        printf("matricula: ");
        scanf("%d", &turma[i]->matricula);

        printf("nota p1: ");
        scanf("%f", &turma[i]->p1);

        printf("nota p2: ");
        scanf("%f", &turma[i]->p2);

        printf("nota p3: ");
        scanf("%f", &turma[i]->p3);
    }

    imprimeDados(n,turma);

    printf("lista de alunos aprovados:\n");
    imprime_aprovados(n,turma);

    printf("media da turma eh: %.2f\n", media_turma(n,turma));


    for(int i=0;i<n;i++){
        free(turma[i]->nome);
    }
    for(int i=0;i<n;i++){
        free(turma[i]);
    }

    free(turma);


    return 0;
}