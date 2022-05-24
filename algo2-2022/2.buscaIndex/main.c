#include "Aluno.h"
#include "IndexHandler.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

//menu de opcoes de comandos
#define ESCOLHA 7
#define INSERT "insert\0"
#define SEARCH "search\0"
#define DELETE "delete\0"
#define EXIT "exit\0"

//arquivos de dados
#define REGFILE_NAME "registers.dat"

//prototipos de funcoes de execucao
void clear_buffer();
void runCode();

//funcao principal MAIN
int main(){
    runCode();
    return 0;
}

//limpa a entrada do stdin
void clear_buffer(){
     while ((getchar()) != '\n'); 
}

//executa o menu principal e o caminho primario do programa
void runCode(){
    //variaveis de entrada
    char escolha[ESCOLHA];
    int reg_index;
    Aluno aluno;

    //arquivos
    FILE *registers = fopen(REGFILE_NAME, "wb+");
    FILE *index_file = fopen(INDEXFILE_NAME, "wb+");

    //variaveis de controle
    int mem_size = 0;
    int last_pos;
    int reg_pos;
    Index *memory = malloc(sizeof(Index));

    while(strcmp(escolha, EXIT) != 0){
        scanf("%[^  \n]", escolha);

        if(strcmp(escolha, INSERT) == 0){
            scanf(" %d,%[^,],%[^,],%[^,],%f", &aluno.nusp, aluno.nome, aluno.sobrenome, aluno.curso, &aluno.nota);

            clear_buffer();

            if(search_for_index(memory, mem_size, aluno.nusp) >= 0){
                printf("O Registro ja existe!");
                printf("\n");
            }
            else{
                /* CONSIDERACAO: nos tentamos colocar esse monstro abaixo em uma funcao porem foram muitos erros
                de casting e segmentation fault, entao optamos por deixar assim (com dor no coracao).
                */
                mem_size += 1;
                memory = realloc(memory, mem_size * sizeof(Index));
                memory[mem_size-1].index = aluno.nusp;
                fseek(registers, 0, SEEK_END);
                last_pos = ftell(registers) / sizeof(Aluno);
                memory[mem_size-1].file_pos = last_pos;
                fwrite(&aluno.nusp, sizeof(int), 1, registers);
                fwrite(&aluno.nome, NOME_LENGTH, 1, registers);
                fwrite(&aluno.sobrenome, SOBRENOME_LENGHT, 1, registers);
                fwrite(&aluno.curso, CURSO_LENGTH, 1, registers);
                fwrite(&aluno.nota, sizeof(float), 1, registers);
            }
        }
        else{
            if(strcmp(escolha, SEARCH) == 0){
                scanf(" %d", &reg_index);

                clear_buffer();

                reg_pos = search_for_index(memory, mem_size, reg_index);

                if(reg_pos < 0){
                    printf("Registro nao encontrado!");
                    printf("\n");
                }
                else{
                    //mesmo caso da consideracao anterior
                    fseek(registers, reg_pos * sizeof(Aluno), SEEK_SET);
                    fread(&aluno.nusp, sizeof(int), 1, registers);
                    fread(&aluno.nome, NOME_LENGTH, 1, registers);
                    fread(&aluno.sobrenome, SOBRENOME_LENGHT, 1, registers);
                    fread(&aluno.curso, CURSO_LENGTH, 1, registers);
                    fread(&aluno.nota, sizeof(float), 1, registers);

                    print_data_aluno(aluno);
                    printf("\n");
                }
            }
            else if (strcmp(escolha, DELETE) == 0){
                scanf(" %d", &reg_index);

                clear_buffer();

                if(search_for_index(memory, mem_size, reg_index) >= 0){
                    search_and_delete(memory, mem_size, reg_index);
                }
            }  
        }
    }

    //gera o arquivo de indices e fecha os arquivos abertos
    write_index_on_file(memory, index_file, mem_size);
    fclose(registers);
}