/**********************************************************************
 * Main for reversing a wav file, reads file input from command line
 * and reverses argued filename into new file. Currently for 1 channel
 * 1 alignment.
 * @author Tristan James
 *********************************************************************/


#include <stdio.h>
#include "wav.h"
#include "file.h"
#include <string.h>

/**********************************************************************
 * Main function for reversing a wav file, handles reading and writing
 * of file
 * @param argc number of arguments
 * @param argv array of arguments
 * @return error code
 *********************************************************************/
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not enough arguments, exiting\n");
        return -1;
    }
    char *fileName = argv[1];
    char *newName = argv[2];
    char *buffer = NULL;
    size_t size = read_file(fileName, &buffer);

    wav_file *file = parse(buffer);
    if (file == NULL) {
        return -1;
    }


    printf("File: %s\n", fileName);
    printf("=====================\n");
    printf("- File size is %zu. Read %u bytes.\n", size, (unsigned int) size - 8);
    printf("- Format is \"%s\" with format data length %d.\n", file->format, file->formatLength);
    printf("- Format type is %s.\n", file->wave);
    printf("- %d channels with a sample rate of %d.\n", file->channels, file->rate);
    printf("- %d byte rate, %d alignment, %d bits per sample\n", file->byteRate, file->alignment, file->bps);
    printf("- Data is %s, and data size is %d\n", file->dataStart, file->dataSize);
    printf("Beginning Reversing...\n");

    //reverse here
    char *reverseBuffer;
    read_file(fileName, &reverseBuffer);

    for (int i = 0; i < size - 44; i += 1) {
        reverseBuffer[44 + i] = buffer[size - 2 - i];
        reverseBuffer[44 + 2 + i] = buffer[size - i];
    }

    write_file(newName, reverseBuffer, size);
    free(buffer);

    printf("Reverse Successful\n");
    return 0;
}
