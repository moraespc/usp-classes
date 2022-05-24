/* 
Este codigo foi feito pelos alunos
Flavio Calaza
Paulo Cesar de Moraes Filho
*/
#include <math.h>
#include "BinaryFileHandler.h"

#define FILE_NAME "entradas.dat"

int main(){
    FILE* arquivo;
    Aluno aluno;
    int nro_registros=0;

    remove(FILE_NAME);
    arquivo = fopen(FILE_NAME, "wb+");

    while(scanf("%d,%[^,],%[^,],%f", &aluno.nusp, 
          aluno.nome_completo, aluno.curso, &aluno.nota)==4){
        writeDataOnFile(arquivo, aluno);
        
    }
    
    nro_registros = countDataInFile(arquivo);

    for(int i= nro_registros-9; i<=nro_registros; i++){
        readSpecificDataFromFile(arquivo, i);

        if(i<nro_registros){
            printf("\n");   
        }
    }

    return 0;
    
}