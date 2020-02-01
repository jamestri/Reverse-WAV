//
// Created by bunny on 1/23/2020.
//

#ifndef REVERSEWAV_WAV_H
#define REVERSEWAV_WAV_H
typedef struct wav_file{
    char riff[4];
    int chunk;
    char wave[4];
    char format[4];
    int formatLength;
    short fmtType;
    short channels;
    int rate;
    int byteRate;
    short alignment;
    short bps;
    char dataStart[4];
    int dataSize;
    char* data;
} wav_file;

wav_file* parse(char* contents);
#endif //REVERSEWAV_WAV_H
