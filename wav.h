/**********************************************************************
 * Header for wav_file, holds base components for parsing a wav file.
 * @author Tristan James
 *********************************************************************/

#ifndef REVERSEWAV_WAV_H
#define REVERSEWAV_WAV_H
/**********************************************************************
 * Data Structure to hold data from wav file.
 *********************************************************************/
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

/**********************************************************************
 * Creates a wav_file struct based on inputted buffer.
 * @param contents buffer to make wav_file.
 * @return wav_file.
 *********************************************************************/
wav_file* parse(char* contents);
#endif //REVERSEWAV_WAV_H
