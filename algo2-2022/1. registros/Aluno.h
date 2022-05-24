// estrutura de armazenamento dos dados de alunos
#ifndef ALUNO_H
#define ALUNO_H

// incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definicao de constantes
#define NOME_LEGNTH 50
#define CURSO_LENGTH 50

// estrutura de dados "Aluno"
typedef struct Aluno{
    int nusp;
    char nome_completo[NOME_LEGNTH];
    char curso[CURSO_LENGTH];
    float nota;
} Aluno;

//funcoes relativas a estrutura Aluno
void readDataFromFile(FILE* filePointer); //le e imprime um registro (posicao do ponteiro)
void readSpecificDataFromFile(FILE* filePointer, int pos_byte); // le um registro em uma posicao especifica
void printDataAluno(Aluno aluno); //imprime os dados do registro no console
void writeDataOnFile(FILE* filePointer, Aluno aluno);//escreve o registro no arquivo binario

#endif // ALUNO_H