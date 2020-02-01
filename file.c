/**********************************************************************
 * Implementation of functions defined in file.h.
 * @author Tristan James
 *********************************************************************/

#include "file.h"
#include <stdio.h>

size_t read_file(char* filename, char** buffer){
    FILE *fp;
    fp = fopen(filename, "rb");
    //finds length of file
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *buffer = malloc(size * sizeof(char));
    fread(*buffer, sizeof(char), size, fp);
    fclose(fp);
    return size;
}
size_t write_file(char* filename, char* buffer, size_t size){
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL){ //if something goes wrong
        printf("oof\n");
    }
    fwrite(buffer, size, 1, fp);
    //find new size of file to compare
    fseek(fp, 0L, SEEK_END);
    size_t newSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    fclose(fp);
    free(buffer);
    return newSize;
}
