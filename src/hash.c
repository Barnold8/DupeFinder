#include <stdio.h>
#include <stdlib.h>

//http://www.cse.yorku.ca/~oz/hash.html

unsigned long fileHash(FILE* fptr, unsigned int buffer_size){

    unsigned char *buffer = malloc(buffer_size);
    char* prints[3] = {"Hashing.\n", "Hashing..\n", "Hashing...\n"};
    int printPointer = 0;
    int iteration_count = 0;

    if (!buffer) {
        printf("Program-Error: Memory allocation failed!\n");
        return 1;
    }

    size_t bytesRead;
    unsigned long hash = 5381;
 
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fptr)) > 0) {

        if(iteration_count % 5000000 == 0){
            #ifdef _WIN32
                system("cls"); 
            #else
                system("clear"); 
            #endif
            printf("\r%s",prints[printPointer]);
            printPointer++;
            if(printPointer >2)printPointer = 0;
        }

        for (size_t i = 0; i < bytesRead; i++) {
            hash = ((hash << 5) + hash) + buffer[i];  
        }

        iteration_count++;
    }
    
    free(buffer);


    #ifdef _WIN32
    system("cls"); 
    #else
        system("clear"); 
    #endif

    return hash;

}

