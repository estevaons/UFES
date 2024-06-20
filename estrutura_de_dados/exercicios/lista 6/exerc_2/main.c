#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"listaHet.h"

int main(){

    Aluno* aluno_1 = iniciaAluno("Aluno1",31231,6.7);
    Aluno* aluno_2 = iniciaAluno("Aluno2", 32154,8.7);
    Aluno* aluno_3 = iniciaAluno("Aluno3", 321, 10.0);

    Professor* professor_1 = iniciaProfessor(231,"Professor1",43243.53);
    Professor* professor_2 = iniciaProfessor(3211,"Professor2",6434.32);
    Professor* professor_3 = iniciaProfessor(3132,"Professor3",123.432);
    
    ListaHet* lista = iniciaLista();

    insereAluno(lista,aluno_1);
    insereAluno(lista,aluno_2);
    insereAluno(lista,aluno_3);

    insereProfessor(lista,professor_1);
    insereProfessor(lista,professor_2);
    insereProfessor(lista,professor_3);

    printf("imprimindo lista\n");
    imprimeLista(lista);

    printf("valor do churrasco: %.2f\n",valorChurrasco(lista));

    liberaAluno(aluno_1);
    liberaAluno(aluno_2);
    liberaAluno(aluno_3);

    liberaProfessor(professor_1);
    liberaProfessor(professor_2);
    liberaProfessor(professor_3);

    liberaLista(lista);

    return 0;
}