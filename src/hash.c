#include <stdio.h>

//http://www.cse.yorku.ca/~oz/hash.html

void fileHash(FILE* fptr){

    //TODO read file byte by byte and continue hash

    int byte;
    long position = 0;  // Track the byte position
    unsigned long hash = 5381;

    while ((byte = fgetc(fptr)) != EOF) {
        // Each byte is an int (0–255), EOF is -1
        hash = ((hash << 5) + hash) + byte;  // hash * 33 + data[i]
        // position++;
    }

    printf("Resulting hash: %d\n",hash);

}

