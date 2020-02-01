#include <stdio.h>
#include "wav.h"
#include "file.h"
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Not enough arguments, exiting\n");
        return -1;
    }
    char* fileName = argv[1];
    char* newName = argv[2];
    char *buffer = NULL;
    size_t size = read_file(fileName, &buffer);
    wav_file* file = parse(buffer);
    if (file == NULL){
        return -1;
    }



    printf("File: %s\n", fileName);
    printf("=====================\n");
    printf("- File size is %d. Read %d bytes.\n", size, size - 8);
    printf("- Format is \"%s\" with format data length %d.\n", file->format, file->formatLength);
    printf("- Format type is %s.\n", file->wave);
    printf("- %d channels with a sample rate of %d.\n", file->channels, file->rate);
    printf("- %d byte rate, %d alignment, %d bits per sample\n", file->byteRate, file->alignment, file->bps);
    printf("- Data is %s, and data size is %d\n", file->dataStart, file->dataSize);
    printf("Beginning Reversing...\n");

    //reverse here
    char* reverseBuffer = NULL;
    memcpy(reverseBuffer, file->data, file->dataSize);

    for (int i = 0; i < size - 44; i += file->alignment) {
        reverseBuffer[i] = buffer[file->dataSize - file->alignment/2 - i];
        reverseBuffer[file->alignment/2 + i] = buffer[file->dataSize - i];
    }
    file->data = reverseBuffer;
    memcpy(buffer, file, size);
    write_file(newName, buffer, size);

    printf("Reverse Successful I hope\n");


    return 0;
}
