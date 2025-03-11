#ifndef MEMORY
#define MEMORY
#include <stddef.h>


#include "fileSystem.h"  

typedef struct dynamic_int_array {
    int* items;
    size_t count;
    size_t capacity;
} intArray;

typedef struct dynamic_fileptr_array {
    hashedFile* items; 
    size_t count;
    size_t capacity;
} filePtrArray;

void addFilePtrElements(filePtrArray* filePtrArray, hashedFile _filePtr);

#endif
