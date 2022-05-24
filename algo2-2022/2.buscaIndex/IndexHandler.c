#include "IndexHandler.h"

//procura pelo indice
int search_for_index(Index *mem, int msize, int idx){
    if(msize == 0){
        return -1;
    }
    else{
        for(int i=0; i<msize; i++){
            if(mem[i].index == idx){
                return mem[i].file_pos;
            }
        }
        return -1;
    }
}

//procura pelo indice e remove logicamente um registro
void search_and_delete(Index *mem, int msize, int idx){
    for(int i=0; i<msize; i++){
        if(mem[i].index == idx){
            mem[i]. index = -1;
        }
    }
}

//escreve os indices em um arquivo
void write_index_on_file(Index *mem, FILE *f_ptr, int s_mem){
    remove(INDEXFILE_NAME);

    f_ptr = fopen(INDEXFILE_NAME, "wb+");
    
    for(int i=0; i<s_mem; i++){
        fwrite(&mem[i].index, sizeof(int), 1, f_ptr);
        fwrite(&mem[i].file_pos, sizeof(int), 1, f_ptr);
    }

    fclose(f_ptr);
}