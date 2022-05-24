#include "Aluno.h"

//imprime um registro de aluno no formato solicitado
void print_data_aluno(Aluno aluno){
    printf("-------------------------------\n");
    printf("USP number: %d\n", aluno.nusp);
    printf("Name: %s\n", aluno.nome);
    printf("Surname: %s\n", aluno.sobrenome);
    printf("Course: %s\n", aluno.curso);
    printf("Test grade: %.2f\n", aluno.nota);
    printf("-------------------------------");
}
                