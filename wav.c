//
// Created by bunny on 1/23/2020.
//

#include "wav.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

wav_file* parse(char* contents){
    wav_file* file = contents;
//    int j = 0;
//    char stuff[4];
//    char smallStuff[2];
//    for (int i = 8; i < 12; ++i) {
//        file.wave[j] = contents[i];
//        ++j;
//    }
//    file.wave[4] =  '\0';
//    char* WAVE = "WAVE";
//    if (strcmp(file.wave, WAVE) == 0) {
//        printf("Not a wave file\n");
//        return NULL;
//    }
//    j = 0;
//    for (int i = 12; i < 16; ++i) {
//        file.format[j] = contents[i];
//        ++j;
//    }
//    file.format[4] = '\0';
//    for (int i = 16; i < 20; ++i) {
//        stuff[j] = contents[i];
//        ++j;
//    }
//    file.formatLength = atoi(stuff);
//
//    //copy numbers to ints
//    //int sampRate;
//    j = 0;
//    for (int i = 22; i < 24; ++i) {
//        smallStuff[j] = contents[i];
//        ++j;
//    }
//    file.channels = strtol(smallStuff, NULL, 10);
//
//    j = 0;
//    for (int i = 24; i < 28; ++i) {
//        stuff[j] = contents[i];
//        ++j;
//    }
//    file.rate = atoi(stuff);
//    //int* bitsPerSamp;
//    j = 0;
//    for (int i = 32; i < 34; ++i) {
//        smallStuff[j] = contents[i];
//        ++j;
//    }
//    file.alignment = strtol(smallStuff, NULL, 10);
//
//    j = 0;
//    for (int i = 34; i < 36; ++i) {
//        smallStuff[j] = contents[i];
//        ++j;
//    }
//    file.bps = atoi(smallStuff);
//    //int* size;
//    j = 0;
//    for (int i = 36; i < 40; ++i) {
//        file.dataStart[j] = contents[i];
//        ++j;
//    }
//    file.dataStart[4] = '\0';
//
//    j = 0;
//    for (int i = 40; i < 44; ++i) {
//        stuff[j] = contents[i];
//        ++j;
//    }
//    file.dataSize = atoi(stuff);
//    file.data = &contents[44];
    return file;
}