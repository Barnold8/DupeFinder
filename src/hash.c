#include <stdio.h>

void fileHash(FILE* fptr){

    //TODO read file byte by byte and continue hash

    int byte;
    long position = 0;  // Track the byte position

    while ((byte = fgetc(fptr)) != EOF) {
        // Each byte is an int (0–255), EOF is -1
        printf("Byte %ld: %d\n", position, byte);
        position++;
    }

}