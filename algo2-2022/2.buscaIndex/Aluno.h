#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IndexHandler.h"

//valores escolhidos arbitrariamente
#define NOME_LENGTH 40
#define SOBRENOME_LENGHT 40
#define CURSO_LENGTH 100

typedef struct Aluno {
    int nusp;
    char nome[NOME_LENGTH];
    char sobrenome[SOBRENOME_LENGHT];
    char curso[CURSO_LENGTH];
    float nota;
} Aluno;

void print_data_aluno(Aluno);

#endif // ALUNO_H