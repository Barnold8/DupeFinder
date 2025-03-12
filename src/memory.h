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

typedef struct dynamic_string_array {
    char* items; 
    size_t count;
    size_t capacity;
} strArray;

void addFilePtrElements(filePtrArray* filePtrArray, hashedFile _filePtr);

void addFilePtrElements(strArray* stringArray, char* string);

#endif
