#include "BinaryFileHandler.h"

//exibir todos os registros no arquivo
void showAllFileContent(FILE* filepointer){
    int num_registros = 0;
    //posicionar no inicio do arquivo
    rewind(filepointer);
    num_registros = countDataInFile(filepointer);

    //executa para o numero de registros obtidos
    for(int i=0; i<num_registros; i++){
        readDataFromFile(filepointer);
        if(i!= num_registros-1){
            printf("\n");
        }
    }
}

//conta o numero de registros no arquivo
int countDataInFile(FILE* filepointer){
    int num_registros = 0;
    
    fseek(filepointer, 0, SEEK_END);
    num_registros = ftell(filepointer)/sizeof(Aluno);
    fseek(filepointer, 0, SEEK_SET);

    return num_registros;
}