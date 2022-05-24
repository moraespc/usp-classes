#ifndef BINARYFILEHANDLER_H
#define BINARYFILEHANDLER_H

// incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

//definicao de constantes
#define FILE_NAME_SIZE 30 //maximo de caracteres da string do nome do arquivo a ser lido

//funcoes relativas a manipulacao de arquivos
void showAllFileContent(FILE* filepointer); //imprime todos os registros num arquivo
int countDataInFile(FILE* filepointer); //conta o numero de registros num arquivo

#endif //BINARYFILEHANDLER_H

