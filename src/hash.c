#include <stdio.h>
#include <stdlib.h>

//http://www.cse.yorku.ca/~oz/hash.html

unsigned long fileHash(FILE* fptr, unsigned int buffer_size){

    unsigned char *buffer = malloc(buffer_size);

    if (!buffer) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    size_t bytesRead;
    unsigned long hash = 5381;
 
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fptr)) > 0) {

        for (size_t i = 0; i < bytesRead; i++) {
            hash = ((hash << 5) + hash) + buffer[i];  
        }
    }
    
    free(buffer);

    return hash;

}

