#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

#define INDEXFILE_NAME "index.dat"

typedef struct Index{
    int index;
    int file_pos;
} Index;

int search_for_index(Index*, int, int);
void search_and_delete(Index*, int, int);
void write_index_on_file(Index*, FILE*, int);

#endif //INDEXHANDLER_H