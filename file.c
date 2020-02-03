/**********************************************************************
 * Implementation of functions defined in file.h.
 * @author Tristan James
 *********************************************************************/

#include "file.h"
#include <stdio.h>
#include <string.h>

size_t read_file(char* filename, char** buffer){
    FILE *fp;

    if ((fopen_s(&fp, filename, "rb")) != 0){
        perror("Error reading file");
    }
    //finds length of file
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *buffer = malloc(size * sizeof(char));
    if (*buffer == NULL) {
        printf("Error while malloc");
        exit(-1);
    }
    fread(*buffer, sizeof(char), size, fp);
    fclose(fp);
    return size;
}
size_t write_file(char* filename, char* buffer, size_t size){
    FILE *fp;
    if ((fopen_s(&fp, filename, "wb")) != 0){
        perror("Error writing file");
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
