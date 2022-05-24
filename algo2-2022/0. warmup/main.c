/* 
Este codigo foi feito pelos alunos
Flavio Calaza
Paulo Cesar de Moraes Filho
*/
#include <math.h>
#include "BinaryFileHandler.h"

int main(){
    FILE* arquivo;
    char nome_arquivo[FILE_NAME_SIZE];
    int escolha, registro, start_range, end_range;

    //leitura dos dados de entrada
    scanf("%s", nome_arquivo);
    scanf("%d", &escolha);

    if((arquivo = fopen(nome_arquivo, "rb"))){
        int nro_registros = 0;
        
        switch (escolha)
        {
            case 1: //exibe todos os registros do arquivo
                showAllFileContent(arquivo);
                fclose(arquivo);
                break;
    
            case 2: //exibe a metade inferior dos registros
                nro_registros = countDataInFile(arquivo)/2;
                for(int i=1; i<=nro_registros; i++){
                    readSpecificDataFromFile(arquivo, i);
                    if(i!= nro_registros){
                        printf("\n");
                    }
                }
                fclose(arquivo);
                break;

            case 3: //exibe a metade superior dos registros
                nro_registros = countDataInFile(arquivo);
                for(int i = (nro_registros/2)+1; i<= nro_registros; i++){
                    readSpecificDataFromFile(arquivo, i);
                    if(i!= nro_registros){
                        printf("\n");
                    }
                }
                fclose(arquivo);
                break;

            case 4: //exibe a partir de uma range dada
                nro_registros = countDataInFile(arquivo);

                scanf("%d", &start_range);
                scanf("%d", &end_range);

                if(start_range <= 0 || start_range > nro_registros){
                    fclose(arquivo);
                    return 1;
                }
                else{
                    if(end_range <= nro_registros){
                        for(int i=start_range; i<=end_range; i++){
                            readSpecificDataFromFile(arquivo, i);
                            
                            if(i!= end_range){
                                printf("\n");
                            }
                        }
                    }
                    else{
                        for(int i=start_range; i<= nro_registros; i++){
                            readSpecificDataFromFile(arquivo, i);

                            if(i!= nro_registros){
                               printf("\n");
                            }
                        }
                    }
                    fclose(arquivo);
                }
                break;

            case 5: //exibr um registro de posicao especifica
                scanf("%d", &registro);
                nro_registros = countDataInFile(arquivo);
                
                if(registro>0 && registro <= nro_registros){
                    readSpecificDataFromFile(arquivo, registro);
                    fclose(arquivo);
                }
                break;
            default:
            break;
        }

        return 0;
    }
    else{
        return 1;
    }
    //execucao a partir da escolha do usuario
};