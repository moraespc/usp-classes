#include "Aluno.h"

//funcao de leitura da estrutura Aluno a partir de um arquivo
void readDataFromFile(FILE* filePointer){
    Aluno aluno;

    //leitura dos dados
    fread(&aluno.nusp, sizeof(int), 1, filePointer);
    fread(&aluno.nome_completo, NOME_LEGNTH*sizeof(char), 1, filePointer);
    fread(&aluno.curso, CURSO_LENGTH*sizeof(char), 1, filePointer);
    fread(&aluno.nota, sizeof(float), 1, filePointer);

    //exibicao no console
    printDataAluno(aluno);
}

//funcao de leitura da estrutura Aluno a partir de um arquivo
void readSpecificDataFromFile(FILE* filePointer, int pos_byte){
    Aluno aluno;
    //posiciona o ponteiro na posicao desejada
    fseek(filePointer, (pos_byte-1)*sizeof(Aluno), SEEK_SET);
    
    //leitura dos dados
    fread(&aluno.nusp, sizeof(int), 1, filePointer);
    fread(&aluno.nome_completo, sizeof(char), NOME_LEGNTH, filePointer);
    fread(&aluno.curso, sizeof(char), CURSO_LENGTH, filePointer);
    fread(&aluno.nota, sizeof(float), 1, filePointer);

    //exibicao no console
    printDataAluno(aluno);
}

//funcao de exibicao da estrutura Aluno no console
void printDataAluno(Aluno aluno){
    printf("nUSP: %d\n", aluno.nusp);
    printf("Nome: %s\n", aluno.nome_completo);
    printf("Curso: %s\n", aluno.curso);
    printf("Nota: %.2f\n", aluno.nota);
}

