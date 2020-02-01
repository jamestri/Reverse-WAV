/**********************************************************************
 * Header file for reading and writing files based on filenames and
 * inputted buffers.
 * @author Tristan James
 *********************************************************************/

#ifndef REVERSEWAV_FILE_H
#define REVERSEWAV_FILE_H

#include <stdlib.h>
/**********************************************************************
 * Reads a file into the inputted buffer and allocates memory for it.
 * @param filename file to be opened.
 * @param buffer buffer for file contents to live.
 * @return size of file opened.
 *********************************************************************/
size_t read_file(char* filename, char** buffer);

/**********************************************************************
 * Writes to a new file based on the filename and buffer to write to.
 * @param filename new file to write to.
 * @param buffer buffer to write to file.
 * @param size size of file.
 * @return size of written file.
 *********************************************************************/
size_t write_file(char* filename, char* buffer, size_t size);
#endif //REVERSEWAV_FILE_H
