#ifndef aluno_h
#define aluno_h

typedef struct al Aluno;

Aluno* iniciaAluno(char* nome, int matricula, float cr);

char* retornaNomeAluno(Aluno* al);

int retornaMatriculaAluno(Aluno* al);

float retornaCrAluno(Aluno* al);

void imprimeAluno(Aluno* al);

void liberaAluno(Aluno* al);

#endif