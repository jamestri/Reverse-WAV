//
// Created by bunny on 1/23/2020.
//

#ifndef REVERSEWAV_FILE_H
#define REVERSEWAV_FILE_H

//#include <stdio.h>
#include <stdlib.h>
size_t read_file(char* filename, char** buffer);
size_t write_file(char* filename, char* buffer, size_t size);
#endif //REVERSEWAV_FILE_H
