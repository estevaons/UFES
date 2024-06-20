#ifndef professor_h
#define professor_h

typedef struct professor Professor;

Professor* iniciaProfessor(int siape, char* nome, float salario);

void imprimeProfessor(Professor* prof);

int retornaSiapeProfessor(Professor* prof);

float retornaSalarioProfessor(Professor* prof);

char* retornaNomeProfessor(Professor* prof);

void liberaProfessor(Professor* prof);

#endif