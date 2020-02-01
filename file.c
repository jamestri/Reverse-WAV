//
// Created by bunny on 1/23/2020.
//

#include "file.h"
#include <stdio.h>
size_t read_file(char* filename, char** buffer){
    FILE *fp;
    fp = fopen(filename, "rb");
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *buffer = malloc(size * sizeof(char));
    fread(*buffer, sizeof(char), size, fp);
    fclose(fp);
    //return sizeof(&buffer);
    return size;
}
size_t write_file(char* filename, char* buffer, size_t size){
    FILE *fp;
    fp = fopen(filename, "wb");
    fputs(buffer, fp);
    realloc(buffer, size);
    fclose(fp);
}
